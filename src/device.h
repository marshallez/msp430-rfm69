#ifndef DEVICE_H_
#define DEVICE_H_

#define CPU_F               ((double)1000000)
#define delay_ms(delay)     __delay_cycles((long)(CPU_F*(((double)delay)/1000.0)))

#endif /* DEVICE_H_ */
