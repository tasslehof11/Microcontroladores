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
char num = 0; //num va 0 a 255 (8 bits)
signed num2=0;//num2 va de -128 a +127
int  val = 0;//val va de 0 a 65535 16 bits)
signed int val2 = 0;//val va de -32768 a +32767
float pi = 3.141516;//pi es de 24 bits coma flotante
void main()
{
    TRISD = 0;
    LATD = 0;
    LATD = 0x40;
LAZO:
    goto LAZO;
}


