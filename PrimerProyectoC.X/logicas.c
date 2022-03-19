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
char num = 0,a=0,b=0;
//Y, O, NEG, MAYOR QUE,MENOR QUE,IGUAL QUE
//DIFERENTE DE, MAYOR O IGUAL QUE, MENOR O IGUAL
//QUE
//VERDADERO != 0
//FALSO = 0
void main()
{
    a = 10;b=9;
    num = a==b; //num=0
    num = a!=b; //num=1
    num = a>b;  //num=1
    num = a>=b; //num=1
    num = a<b;  //num=0
    num = a<=b; //num=0
    num = a&&b; //num=1
    num = a&b;  //num=00001010 and 00001001=num=8
    num = a||b; //num=1
    num = a|b;  //num=00001011 = 11
    num = !b;   //num=0
    num = ~b;   //num=11110110
    while(1);
}
