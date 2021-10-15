
#include <p18f2520.h>
#include <adc.h>
#include <usart.h>
#include <portb.h>
#include <spi.h>
#include <timers.h>
#include <delays.h>

#pragma config OSC = HS     /*set osc mode to HS */
#pragma config WDT = OFF    /* set watchdog timer off */
#pragma config LVP = OFF    /* Low Voltage Programming Off */
#pragma config DEBUG = OFF  /* Compile without extra Debug compile Code */

const unsigned long nof = 625000 / 65535;   // number of overflows
const unsigned int nor = 625000 % 65535;    // remainder

extern ram volatile unsigned int ovf;
extern ram volatile unsigned int rem;
extern ram volatile unsigned int ovf_v;
extern ram volatile unsigned int rem_v;
extern ram volatile unsigned long FRQv;
unsigned char startup = 0xFF;

extern const rom unsigned char *user_options;

void main(void) {
    
    ovf = 625000 / 65535;          // Number of timer overflows to keep track off
    rem = 625000 % 65535;          // Remainder in case of overflow
    ovf_v = ovf;
    rem_v = rem;
    FRQv = 65535 - rem;
    
    configure_uart(2400);           // only 2400 supported 
    putrsUSART(user_options); // User instructions
    general_setup();
     while (putcSPI(0x0000) == -1) SSPCON1bits.WCOL = 0;      // lowest power consumption
     while (putcSPI(0x0000) == -1) SSPCON1bits.WCOL = 0;
    
    while(1) Delay10KTCYx(0);
}
