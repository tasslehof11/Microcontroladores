#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config FOSC = XTPLL_XT     // Oscillator Selection bits (EC oscillator, CLKO function on RA6 (EC))
#pragma config PWRT = ON       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config WDT = OFF         // Watchdog Timer Enable bit (WDT enabled)
#pragma config PBADEN = OFF      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config LVP = OFF         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#include <xc.h>
#define _XTAL_FREQ 48000000UL

typedef union{
    char _byte;
    int  _word;
    struct{
        char bit0: 1;char bit1: 1;
        char bit2: 1;char bit3: 1;
        char bit4: 1;char bit5: 1;
        char bit6: 1;char bit7: 1;
        char bit8: 1;char bit9: 1;
        char bit10: 1;char bit11: 1;
        char bit12: 1;char bit13: 1;
        char bit14: 1;char bit15: 1;
    }_bits;
}tipo_dato;
tipo_dato dato;
void main()
{
    dato._word=0x8765;
    LATBbits.LATB0=dato._bits.bit5;
    while(1);
}