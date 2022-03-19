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
/*Autor: Sergio Salas
  Fecha: 10-10-2017 Ver 2.0
  El siguiente programa tiene como fin mostrar
 * el funcionamiento de los condicinales en ANSI
 * C.
 * Variables:
 * a su fin es demostrar la funcionalidad del if
 * b su fin es demostrar la funcionalidad del if
 */
char num=0,a=0,b=0;
void main()
{
    a=10;b=8;
    if(b<a) 
        num=4;
    else if(b==a)
    {
        num=6;
        b=12;
    }
    else if(b>a && b<40)
        num=7;
    else
        num=8;
    while(1);
}
