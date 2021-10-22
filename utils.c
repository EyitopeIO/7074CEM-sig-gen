#include <usart.h>
#include <spi.h>
#include <adc.h>
#include <portb.h>
#include <spi.h>
#include <timers.h>



const rom unsigned int WAVEFORM_triangle [] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 
65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144,
145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 
176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210,
211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 
246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 236, 235, 234, 233, 232,
231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 
196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162,
161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127,
126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89,
88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42,
41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
};

const rom unsigned int WAVEFORM_rampup [] = {
0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120,
128, 136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224,
232, 240, 248, 256, 264, 272, 280, 288, 296, 304, 312, 320, 328,
336, 344, 352, 360, 368, 376, 384, 392, 400, 408, 416, 424, 432,
440, 448, 456, 464, 472, 480, 488, 496, 504      
};

const rom unsigned int WAVEFORM_rampdown [] = {
    512, 504, 496, 488, 480, 472, 464, 456, 448, 440, 432, 424, 416, 408, 400, 392, 384,
    376, 368, 360, 352, 344, 336, 328, 320, 312, 304, 296, 288, 280, 272, 264, 256, 248, 
    240, 232, 224, 216, 208, 200, 192, 184, 176, 168, 160, 152, 144, 136, 128, 120, 112, 
    104, 96, 88, 80, 72, 64, 56, 48, 40, 32, 24, 16, 8, 0
};

const rom unsigned int WAVEFORM_square [] = {
    0, 1023
};

const rom unsigned int WAVEFORM_pulse [] = {
     0, 1023
};

const rom unsigned int WAVEFORM_sine [] = { 
0, 6, 12, 18, 25, 31, 37, 43, 50, 56, 62, 68, 75, 81, 87, 93, 99, 106, 112, 118, 124, 130, 136, 142,
148, 154, 160, 166, 172, 178, 184, 190, 195, 201, 207, 213, 218, 224, 230, 235, 241, 246, 252, 257,
263, 268, 273, 279, 284, 289, 294, 299, 304, 310, 314, 319, 324, 329, 334, 339, 343, 348, 353, 357,
362, 366, 370, 375, 379, 383, 387, 391, 395, 399, 403, 407, 411, 414, 418, 422, 425, 429, 432, 435,
439, 442, 445, 448, 451, 454, 457, 460, 462, 465, 468, 470, 473, 475, 477, 479, 482, 484, 486, 488,
489, 491, 493, 495, 496, 498, 499, 500, 502, 503, 504, 505, 506, 507, 508, 508, 509, 510, 510, 511, 
511, 511, 511, 511, 512, 511, 511, 511, 511, 511, 510, 510, 509, 508, 508, 507, 506, 505, 504, 503,
502, 500, 499, 498, 496, 495, 493, 491, 489, 488, 486, 484, 482, 479, 477, 475, 473, 470, 468, 465,
462, 460, 457, 454, 451, 448, 445, 442, 439, 435, 432, 429, 425, 422, 418, 414, 411, 407, 403, 399,
395, 391, 387, 383, 379, 375, 370, 366, 362, 357, 353, 348, 343, 339, 334, 329, 324, 319, 314, 310,
304, 299, 294, 289, 284, 279, 273, 268, 263, 257, 252, 246, 241, 235, 230, 224, 218, 213, 207, 201,
195, 190, 184, 178, 172, 166, 160, 154, 148, 142, 136, 130, 124, 118, 112, 106, 99, 93, 87, 81, 75,
68, 62, 56, 50, 43, 37, 31, 25, 18, 12, 6, 0, 6, 12, 18, 25, 31, 37, 43, 50, 56, 62, 68, 75, 81, 87, 93,
99, 106, 112, 118, 124, 130, 136, 142, 148, 154, 160, 166, 172, 178, 184, 190, 195, 201, 207, 213,
218, 224, 230, 235, 241, 246, 252, 257, 263, 268, 273, 279, 284, 289, 294, 299, 304, 310, 314, 319,
324, 329, 334, 339, 343, 348, 353, 357, 362, 366, 370, 375, 379, 383, 387, 391, 395, 399, 403, 407,
411, 414, 418, 422, 425, 429, 432, 435, 439, 442, 445, 448, 451, 454, 457, 460, 462, 465, 468, 470,
473, 475, 477, 479, 482, 484, 486, 488, 489, 491, 493, 495, 496, 498, 499, 500, 502, 503, 504, 505,
506, 507, 508, 508, 509, 510, 510, 511, 511, 511, 511, 511, 512, 511, 511, 511, 511, 511, 510, 510,
509, 508, 508, 507, 506, 505, 504, 503, 502, 500, 499, 498, 496, 495, 493, 491, 489, 488, 486, 484,
482, 479, 477, 475, 473, 470, 468, 465, 462, 460, 457, 454, 451, 448, 445, 442, 439, 435, 432, 429,
425, 422, 418, 414, 411, 407, 403, 399, 395, 391, 387, 383, 379, 375, 370, 366, 362, 357, 353, 348,
343, 339, 334, 329, 324, 319, 314, 310, 304, 299, 294, 289, 284, 279, 273, 268, 263, 257, 252, 246,
241, 235, 230, 224, 218, 213, 207, 201, 195, 190, 184, 178, 172, 166, 160, 154, 148, 142, 136, 130,
124, 118, 112, 106, 99, 93, 87, 81, 75, 68, 62, 56, 50, 43, 37, 31, 25, 18, 12, 6
};


const rom enum WAV_SEL_E { TRIANGLE = 0, RAMP_UP = 1, RAMP_DOWN = 2, SQUARE = 3, SINE = 4, PULSE = 5};
const rom unsigned char WAVE_SEL [] = {'A','B','C','D','E','F'};

const rom enum FREQ_SEL_E { HZ_2 = 0, HZ_5 = 1, HZ_10 = 2, HZ_20 = 3, HZ_50 = 4, HZ_100 = 5};
const rom unsigned char FREQ_SEL [] = {2, 5, 10, 20, 50, 100}; 

const rom unsigned int WAVEFORM_MAX_PTS [] = {512, 64, 65, 2, 512, 2};

ram volatile unsigned long DACv = 0;      // 32 bits variable necessary for git
ram volatile unsigned long DACm = 0;      // 32 bits variable necessary for git

ram volatile unsigned long FRQv = 0;
ram volatile unsigned char DACH = 0;
ram volatile unsigned char DACL = 0;

ram volatile unsigned char rx;
ram volatile unsigned char wave_now;
ram volatile unsigned char freq_now;

extern unsigned char startup;

rom far const volatile unsigned int *ptr_current_wav;

const rom unsigned char wave_sel_max = 6;
const rom unsigned char freq_sel_max = 6;
const ram unsigned double clock_period = 0.0000016;          // Clock frequency = 625 kHz
ram volatile unsigned long ticks = 0;             // Number of ticks required
const ram unsigned int max_t = 65535;
ram volatile unsigned int WAVEFORM_max_points = 1024;
ram volatile unsigned char use_ovf = 0;

ram volatile unsigned int ovf = 0;          // Number of timer overflows to keep track off
ram volatile unsigned int rem = 0;          // Remainder in case of overflow
ram volatile unsigned int ovf_v = 0;
ram volatile unsigned int rem_v = 0;

ram volatile unsigned int wavi = 0;         // Index of wave values
ram volatile unsigned int frqs_i = 0;         // FREQ_SEL index
ram volatile unsigned int wavs_i = 0;         // WAV_SEL index

rom const unsigned char *user_options = 
    "*** Select with the character in brackets ***\r\n"
    "(A) Triangle wave\r\n"
    "(B) Ramp Up Sawtooth wave\r\n"
    "(C) Ramp Down Sawtooth wave\r\n"
    "(D) Square wave\r\n"
    "(E) Sine wave\r\n"
    "(F) Pulse wave\r\n"
    "(1) 2Hz\r\n"
    "(2) 5Hz\r\n"
    "(3) 10Hz\r\n"
    "(4) 20Hz\r\n"
    "(5) 50Hz\r\n"
    "(6) 100Hz\r\n";

void configure_uart(unsigned int baudrate);
void high_priority_handler(void);
void low_priority_handler(void);
void general_setup(void);

#pragma code high_priority_event = 0x08
void high_priority_event(void) {
    _asm
    GOTO high_priority_handler
    _endasm
}
#pragma code

#pragma code low_priority_event = 0x18
void low_priority_event(void) {
    _asm
    GOTO low_priority_handler
    _endasm
}
#pragma code

#pragma interrupt high_priority_handler
void high_priority_handler(void) {
    
    PIE1bits.RCIE = 0;               // Prevent interrupt in interrupt
    INTCON3bits.INT1E = 0;
    INTCON3bits.INT2E = 0;
    
    if (startup) startup = 0x00;     
    
    if (PIR1bits.RCIF == 1) {
        rx = RCREG;
    }
    else if (INTCON3bits.INT1IF == 1) {
        INTCON3bits.INT1IF = 0;
        wave_now = WAVE_SEL[wavs_i++];
        rx = wave_now;
        if (wavs_i >= wave_sel_max) wavs_i = 0;
    }
    else if (INTCON3bits.INT2IF == 1) {
        INTCON3bits.INT2IF = 0;
        freq_now = FREQ_SEL[frqs_i++];
        rx = frqs_i + (unsigned int)'0';
        if (frqs_i >= freq_sel_max) frqs_i = 0;
    }  
    switch(rx) {
        case 'A':
            ptr_current_wav = &WAVEFORM_triangle[0];
            // wavs_i = TRIANGLE;
            WAVEFORM_max_points = WAVEFORM_MAX_PTS[TRIANGLE];
            break;
        case 'B':
            ptr_current_wav = &WAVEFORM_rampup[0];
            // wavs_i = RAMP_UP;
            WAVEFORM_max_points = WAVEFORM_MAX_PTS[RAMP_UP];
            break;
        case 'C':
            // wavs_i = RAMP_DOWN;
            ptr_current_wav = &WAVEFORM_rampdown[0];
            WAVEFORM_max_points = WAVEFORM_MAX_PTS[RAMP_DOWN];
            break;
        case 'D':
            // wavs_i = SQUARE;
            ptr_current_wav = &WAVEFORM_square[0];
            WAVEFORM_max_points = WAVEFORM_MAX_PTS[SQUARE];
            break;
        case 'E':
            // wavs_i = SINE;
            ptr_current_wav = &WAVEFORM_sine[0];
            WAVEFORM_max_points = WAVEFORM_MAX_PTS[SINE];
            break;
        case 'F':
            // wavs_i = PULSE;
            ptr_current_wav = &WAVEFORM_pulse[0];
            WAVEFORM_max_points = WAVEFORM_MAX_PTS[PULSE];
            break;
        case '1':
            freq_now = FREQ_SEL[HZ_2];
            // frqs_i = HZ_2;
            break;
        case '2':
            // frqs_i = HZ_5;
            freq_now = FREQ_SEL[HZ_5];
            break;
        case '3':
            // frqs_i = HZ_10;
            freq_now = FREQ_SEL[HZ_10];
            break;
        case '4':
            // frqs_i = HZ_20;
            freq_now = FREQ_SEL[HZ_20];
            break;
        case '5':
            // frqs_i = HZ_50;
            freq_now = FREQ_SEL[HZ_50];
            break;
        case '6':
            // frqs_i = HZ_100;
            freq_now = FREQ_SEL[HZ_100];
            break;
        default:
            putrsUSART("Invalid input: ");
            putcUSART(rx);
            putrsUSART(" \r\n\r\n");
            break;      
    }
            
     ticks = (unsigned long)(1 / (freq_now * WAVEFORM_max_points * clock_period));
     
     if (ticks < max_t) {      // max_t = 65535
         FRQv = max_t - ticks;
         use_ovf = 0x00;
         ovf = 0;
         ovf_v = 0;
         rem = 0;
         rem_v = 0;
     }
     else {
         ovf = (unsigned int)(ticks / max_t);
         use_ovf = 0xFF;
         rem = ticks % max_t;       // Remainder
         rem_v = rem;
         ovf_v = ovf;
         FRQv = max_t - rem;
     }
    
    wavi = 0;       

    PIE1bits.RCIE = 1;               // Enable interrupts again
    INTCON3bits.INT1E = 1;
    INTCON3bits.INT2E = 1;

}

#pragma interruptlow low_priority_handler
void low_priority_handler(void) {
 
    if (PIR2bits.TMR3IF == 1) {
 
        PIR2bits.TMR3IF = 0;        // Clear overflow flag 
        PIE2bits.TMR3IE = 0;         // Prevent interrupt in interrupt
       
        LATAbits.LATA5 = 0;          // Make CS pin low     
        LATCbits.LATC2 = 1;          // Turn on activity LED   
        
        if ((ovf == 0 && rem == 0) || (ovf_v == 0 && rem_v == 0) ) {                   // ticks < max_t     
            if (use_ovf) {
                WriteTimer3(0);
                ovf_v = ovf;
                rem_v = rem;
            }
            else WriteTimer3(FRQv);       
            DACv = ptr_current_wav[wavi++];
            DACm = DACv;       
            DACv = DACv << 2;
        }    
        else if (ovf_v > 0) {
            WriteTimer3(0);
            ovf_v--;
            DACv = ptr_current_wav[wavi] << 2;
        }
        else if (ovf_v == 0 && rem >= 0) {
            WriteTimer3(FRQv);
            rem_v = 0;
            DACv = ptr_current_wav[wavi] << 2;
            
            if (startup) {
                OSCCONbits.IDLEN = 0;
                Sleep();
            }
        }

        if (!startup) {
            DACH = (unsigned char)(DACv >> 8) ;
            DACL = (unsigned char)DACv;       
            while (putcSPI(DACH) == -1) SSPCON1bits.WCOL = 0;
            while (putcSPI(DACL) == -1) SSPCON1bits.WCOL = 0;

            if (wavi >= WAVEFORM_max_points) wavi = 0;
        }
        
        LATAbits.LATA5 = 1;         // CS pin high to start conversion   
        LATCbits.LATC2 = 0;
        PIE2bits.TMR3IE = 1;         // Enable interrupt     
    }
}

/*
 * Set the baud rate of the UART.  Defaults is 2400.
 * Code is open to further baud rates by adding required cases in the switch statement.
 */
void configure_uart(unsigned int baudrate) {
    
    switch (baudrate) {
        
        case 2400:      // error = -0.03
            
            SPBRG = 0x08;                     // 2400 bps, 20MHz. SPBRG and SPBRGH yields 520 DEC                   
            SPBRGH = 0x02;	 
            TXSTAbits.BRGH = 0;            //  Low speed baud rate     
            BAUDCONbits.BRG16 = 1;      // Use 16 bit baud rate generator 
            TXSTAbits.SYNC = 0;             // Asynchronous mode
            RCSTAbits.SPEN = 1;             // Enable serial port
            RCSTAbits.RX9 = 0;
            RCSTAbits.CREN = 1;
            TXSTAbits.TXEN = 1;              // Transmit enable
            TRISCbits.RC6 = 1;              // Set both .RC6 & .RC7 to 1 
            TRISCbits.RC7 = 1;             
            break;
            
        default:
            break;
    }   
    PIE1bits.RCIE = 1;               // Enable EUSART receive interrupt
    IPR1bits.RCIP = 1;              // Set EUSART interrupt to high priority;
}

/*
 * Configure all peripherals and set defaults
 */
void general_setup(void) {
    
    ADCON1 = 0x0D;                 // All pins digital except RA0 & 1
    TRISCbits.RC2 = 0;              // LED pin set to output
    
    /*
     * Setup interrupts on PORTB
     */
    OpenRB1INT(PORTB_CHANGE_INT_ON & FALLING_EDGE_INT & PORTB_PULLUPS_OFF);
    OpenRB2INT(PORTB_CHANGE_INT_ON & FALLING_EDGE_INT & PORTB_PULLUPS_OFF);
    INTCON3bits.INT1IP = 1;             // Use as high priority interrupt
    INTCON3bits.INT2IP = 1;
    INTCON3bits.INT2IF = 0;             // Clear interrupt flag
    INTCON3bits.INT1IF = 0;

    /*
     * Setup ADC for amplitude and offset adjustment
     */
    // OpenADC(ADC_FOSC_32 & ADC_RIGHT_JUST & ADC_20_TAD, ADC_CH1 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS, 0b1011); 

    /*
     * Setup SPI
     */
    PIE1bits.SSPIE = 0;               // Disable SPI interrupts
    SSPCON1bits.SSPEN = 1;       // Enable SPI
    SSPCON1bits.CKP = 0;
    SSPCON1bits.WCOL = 0;           // No overwrite allowed
    SSPCON1 &= 0xF0;                  // Host mode Fosc/4
    // SSPCON1 &= 0xF2;                  // Host mode Fosc/64

    SSPSTATbits.CKE = 0;
    SSPSTATbits.SMP = 0;		 // Sample in middle
    TRISAbits.TRISA5 = 0;              // Set for SS
    TRISCbits.TRISC5 = 0;             // Cleared for SDO
    TRISCbits.TRISC3 = 0;             // Cleared for SCK
    
    /*
     * Setup timer
     */    
    T3CONbits.TMR3ON = 1;
    T3CONbits.RD16 = 1;         // Use 16 bit RW operation
    T1CONbits.T1OSCEN = 0;    // Disable for power saving
    PIE2bits.TMR3IE = 1;         // Enable timer interrupt
    IPR2bits.TMR3IP = 0;        // Set interrupt to low priority  
    T3CON |= 0x30;               // Set bits 4 & 5 for 1:8 prescaler 
    T3CONbits.TMR3CS = 0;    // Use Fosc/4 clock
    WriteTimer3(0x0000);
    
    /*
     * Setup general interrupts.
     */
    RCONbits.IPEN = 1;              // Enable low priority interrupts
    INTCONbits.GIE = 1;             // Enable global interrupts
    INTCONbits.PEIE = 1;           // Enable all unmasked peripheral interrupts
    
    /*
     * Define starting frequency and waveform
     */
    FRQv = 65229;       // See high priority interrupt for how this was calculated         
    wave_now = WAVE_SEL[TRIANGLE];
    freq_now = FREQ_SEL[HZ_2];
    WAVEFORM_max_points = WAVEFORM_MAX_PTS[TRIANGLE];
    ptr_current_wav = &WAVEFORM_triangle[0];    
}
