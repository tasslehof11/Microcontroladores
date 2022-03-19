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
#include "LCD.h"
#define _XTAL_FREQ 48000000UL
void main()
{
    TRISD = 0;
    __delay_ms(15);
    LCD_CONFIG();
    ESCRIBE_MENSAJE("Peru ira a Rusia",16);
    POS_CURSOR(2,4);
    ESCRIBE_MENSAJE("2018",4);
    __delay_ms(2000);
    BORRAR_LCD();
    ESCRIBE_MENSAJE("Si es que ganan",15);
    POS_CURSOR(2,0);
    ESCRIBE_MENSAJE("a New Zealand",13);
     
    while(1);
            
}