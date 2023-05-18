#include <msp430.h>
#include <string.h>
#include "spi.h"
#include "gpio.h"
#include "device.h"
#include "rfm69.h"

void rfm69_init() {
    P1OUT |= CS;
    P1DIR |= CS;
    P1SEL = MISO | MOSI | SCLK;
    P1SEL2 = MISO | MOSI | SCLK;
    P2SEL |= RST;
    P2DIR |= RST;
    P2OUT &= (~RST);

    // RadioHead-compatible default values (no encryption and 433 mHz frequency)
    rfm69_write(REG_OP_MODE, 0b00000100);
    rfm69_write(REG_FIFO_THRESH, 0b10001111);
    rfm69_write(REG_TEST_DAGC, 0b00110000);
    rfm69_write(REG_TEST_PA_1, 0b01010101);
    rfm69_write(REG_TEST_PA_2, 0b01110000);
    rfm69_write(REG_SYNC_CONFIG, 0b10001000);
    rfm69_write(REG_SYNC_VALUE_1, 0x2D);
    rfm69_write(REG_SYNC_VALUE_2, 0xD4);
    rfm69_write(REG_PREAMBLE_MSB, 0b00000000);
    rfm69_write(REG_PREAMBLE_LSB, 0b00000100);
    rfm69_write(REG_FRF_MSB, 0b01101100);
    rfm69_write(REG_FRF_MID, 0b01000000);
    rfm69_write(REG_FRF_LSB, 0b00000000);
    rfm69_write(REG_DATA_MODUL, 0b00000001);
    rfm69_write(REG_BITRATE_MSB, 0b00000000);
    rfm69_write(REG_BITRATE_LSB, 0b10000000);
    rfm69_write(REG_FDEV_MSB, 0b00010000);
    rfm69_write(REG_FDEV_LSB, 0b00000000);
    rfm69_write(REG_RX_BW, 0b11100000);
    rfm69_write(REG_AFC_BW, 0b11100000);
    rfm69_write(REG_PACKET_CONFIG_1, 0b11010000);
    rfm69_write(REG_PA_LEVEL, 0b01011111);
}

unsigned char rfm69_read(unsigned char address) {
    unsigned char value = 0;
    P1OUT &= (~CS);
    spi_write(address);
    spi_write(0x00);    // Necessary to keep the transaction alive. Won't return any values without this dummy write.
    value = UCA0RXBUF;
    P1OUT |= CS;
    return value;
}

void rfm69_write(unsigned char address, unsigned char value) {
    delay_ms(1);
    P1OUT &= (~CS);
    spi_write((address ^= 0b10000000)); // Writes a 1 to the wnr bit for write access along with the address
    spi_write(value);
    P1OUT |= CS;
}

void rfm69_send(char data_payload[]) {
    int payload_len = strlen(data_payload);
    rfm69_write(REG_FIFO, payload_len + 4);     // number of bytes in the message excluding this byte. 4 header bytes + length of payload in bytes
    rfm69_write(REG_FIFO, 0b11111111);          // destination byte
    rfm69_write(REG_FIFO, 0b11111111);          // node byte
    rfm69_write(REG_FIFO, 0b00000000);          // 0 identifier
    rfm69_write(REG_FIFO, 0b00000000);          // 0 flags

    for (int i = 0; i < strlen(data_payload); i++) {
        rfm69_write(REG_FIFO, data_payload[i]); // data byte
    }

    rfm69_write(REG_DIO_MAPPING1, 0b00000000);
    rfm69_write(REG_OP_MODE, 0b00001100); // transition to tx
    rfm69_write(REG_OP_MODE, 0b00000100); // transition back to idle
}