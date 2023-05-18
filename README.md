<h1>MSP430 RFM69</h1>
<h2>RadioHead-compatible sending of packets using an rfm69 with an MSP430G2553</h2>


<p>Registers are setup for communication with a separate device using the default Radiohead RFM96 values. 
Tested with an ESP32 receiver using micropython drivers found at https://github.com/nohcpy/MicroPython_rfm69.</p>

Minor differences between the above sender
1. The msp430 rfm69 driver defaults to 433.0 mHz instead of 915.0 Mhz
2. The encryption key is removed (must also be removed in the receiver (or added in both) in order to work)
3. Currently only allows for the sending of packets from the msp430. Receiving has not been implemented yet.

Uses the USCI_A0 SPI mode with the following pinout.

P1.1 MISO
P1.2 MOSI
P1.4 SCLK
P1.5 CS
P2.5 RST

Uses the mspdebug (https://github.com/dlbeer/mspdebug) command line tools with the ti gcc msp430 toolchain. An example makefile is provided but would need to be changed to source the proper directories from a linux machine. The files can also be copied to a project in codecomposer studio.