#include <msp430.h> 
#include "spi.h"
#include "rfm69.h"
#include "string.h"
#include "device.h"

void msp430_init() {
    WDTCTL = WDTPW | WDTHOLD; /* Stop watchdog timer */

    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    spi_init();
    rfm69_init();
}

int main(void) {

    msp430_init();

    int messages_to_send = 10;
    char buf[16];
    for (int i = 0; i < messages_to_send; i++) {
        snprintf(buf, 16, "Hello world %d!", i);
        rfm69_send(buf);
        delay_ms(1500);
    }

    return 0;
}