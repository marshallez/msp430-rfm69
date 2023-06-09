#ifndef rfm69_H
#define rfm69_H

#define REG_FIFO                (0x00)
#define REG_OP_MODE             (0x01)
#define REG_DATA_MODUL          (0x02)
#define REG_BITRATE_MSB         (0x03)
#define REG_BITRATE_LSB         (0x04)
#define REG_FDEV_MSB            (0x05)
#define REG_FDEV_LSB            (0x06)
#define REG_FRF_MSB             (0x07)
#define REG_FRF_MID             (0x08)
#define REG_FRF_LSB             (0x09)
#define REG_OSC_1               (0x0A)
#define REG_AFC_CTRL            (0x0B)
#define REG_LISTEN_1            (0x0D)
#define REG_LISTEN_2            (0x0E)
#define REG_LISTEN_3            (0x0F)
#define REG_VERSION             (0x10)
#define REG_PA_LEVEL            (0x11)
#define REG_PA_RAMP             (0x12)
#define REG_OCP                 (0x13)
#define REG_LNA                 (0x18)
#define REG_RX_BW               (0x19)
#define REG_AFC_BW              (0x1A)
#define REG_OOK_PEAK            (0x1B)
#define REG_OOK_AVG             (0x1C)
#define REG_OOK_FIX             (0x1D)
#define REG_AFC_FEI             (0x1E)
#define REG_AFC_MSB             (0x1F)
#define REG_AFC_LSB             (0x20)
#define REG_FEI_MSB             (0x21)
#define REG_FEI_LSB             (0x22)
#define REG_RSSI_CONFIG         (0x23)
#define REG_RSSI_VALUE          (0x24)
#define REG_DIO_MAPPING1        (0x25)
#define REG_DIO_MAPPING2        (0x26)
#define REG_IRQ_FLAGS_1         (0x27)
#define REG_IRQ_FLAGS_2         (0x28)
#define REG_RSSI_THRESH         (0x29)
#define REG_RX_TIMEOUT_1        (0x2A)
#define REG_RX_TIMEOUT_2        (0x2B)
#define REG_PREAMBLE_MSB        (0x2C)
#define REG_PREAMBLE_LSB        (0x2D)
#define REG_SYNC_CONFIG         (0x2E)
#define REG_SYNC_VALUE_1        (0x2F)
#define REG_SYNC_VALUE_2        (0x30)
#define REG_SYNC_VALUE_3        (0x31)
#define REG_SYNC_VALUE_4        (0x32)
#define REG_SYNC_VALUE_5        (0x33)
#define REG_SYNC_VALUE_6        (0x34)
#define REG_SYNC_VALUE_7        (0x35)
#define REG_SYNC_VALUE_8        (0x36)
#define REG_PACKET_CONFIG_1     (0x37)
#define REG_PAYLOAD_LENGTH      (0x38)
#define REG_NODE_ADRS           (0x39)
#define REG_BROADCAST_ADRS      (0x3A)
#define REG_AUTO_MODES          (0x3B)
#define REG_FIFO_THRESH         (0x3C)
#define REG_PACKET_CONFIG_2     (0x3D)
#define REG_AESKEY_1            (0x3E)
#define REG_AESKEY_2            (0x3F)
#define REG_AESKEY_3            (0x40)
#define REG_AESKEY_4            (0x41)
#define REG_AESKEY_5            (0x42)
#define REG_AESKEY_6            (0x43)
#define REG_AESKEY_7            (0x44)
#define REG_AESKEY_8            (0x45)
#define REG_AESKEY_9            (0x46)
#define REG_AESKEY_10           (0x47)
#define REG_AESKEY_11           (0x48)
#define REG_AESKEY_12           (0x49)
#define REG_AESKEY_13           (0x4A)
#define REG_AESKEY_14           (0x4B)
#define REG_AESKEY_15           (0x4C)
#define REG_AESKEY_16           (0x4D)
#define REG_TEMP_1              (0x4E)
#define REG_TEMP_2              (0x4F)
#define REG_TEST_LNA            (0x58)
#define REG_TEST_PA_1           (0x5A)
#define REG_TEST_PA_2           (0x5C)
#define REG_TEST_DAGC           (0x6F)

#define FXOSC = 32000000.0
#define FSTEP = FXOSC / 524288

void rfm69_init();
unsigned char rfm69_read(unsigned char address);
void rfm69_write(unsigned char address, unsigned char value);
void rfm69_send(char data_payload[]);

#endif