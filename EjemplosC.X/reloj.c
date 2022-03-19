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
char seg=50,min=59,hor=23,dia=28,mes=2,anio=16;
char dias_mes[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char cont=0;
void main()
{
    TRISD=0;
    __delay_ms(15);
    LCD_CONFIG();
    ESCRIBE_MENSAJE("Hora:",5);
    POS_CURSOR(2,0);
    ESCRIBE_MENSAJE("Fech:",5);
    
    CURSOR_ONOFF(OFF);
    PIE1bits.TMR1IE=1;
    T1CON = 0b00110001; //Prescaler=8 TMR1ON 23 interrupcions aprox 1 seg
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;
    while(1){
        if(cont==0)
        {
            POS_CURSOR(1,6);
            ENVIA_CHAR(hor/10+'0');
            ENVIA_CHAR(hor%10+'0');
            ENVIA_CHAR(':');
            ENVIA_CHAR(min/10+'0');
            ENVIA_CHAR(min%10+'0');
            ENVIA_CHAR(':');
            ENVIA_CHAR(seg/10+'0');
            ENVIA_CHAR(seg%10+'0');
            POS_CURSOR(2,6);
            ENVIA_CHAR(dia/10+'0');
            ENVIA_CHAR(dia%10+'0');
            ENVIA_CHAR('/');
            ENVIA_CHAR(mes/10+'0');
            ENVIA_CHAR(mes%10+'0');
            ENVIA_CHAR('/');
            ENVIA_CHAR(anio/10+'0');
            ENVIA_CHAR(anio%10+'0');
            
        }
    }
}
void interrupt high_priority timer1(void)
{
    PIR1bits.TMR1IF=0;
    cont++;
    if(cont==15)
    {
        cont=0;
        seg++;
        if(seg==60){seg=0;min++;}
        if(min==60){hor++;min=0;}
        if(hor==24){hor=0;dia++;}
        if(dia>dias_mes[mes]){mes++;dia=1;}
        if(mes==13){mes=1;anio++;}
        if(anio%4==0) dias_mes[2]=29;
        else          dias_mes[2]=28;
    }
}
