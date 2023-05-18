#include <msp430.h>
#include "spi.h"
#include "gpio.h"
#include "device.h"

void spi_write(unsigned char tx_data) {

    while (!(IFG2 & UCA0TXIFG));
    UCA0TXBUF = tx_data;

    while (UCA0STAT & UCBUSY);
}

void spi_init() {
    UCA0CTL0 = UCCKPH | UCMSB | UCMST | UCMODE_0 | UCSYNC;
    UCA0CTL1 = UCSSEL_2 | UCSWRST;
    UCA0BR0 = 8;
    UCA0CTL1 &= ~UCSWRST;
}