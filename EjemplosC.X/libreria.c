#include "libreria.h"
#include <xc.h>

char n_vocales(char mensaje[])
{
    char tam=0;
    while(mensaje[tam]!=0) tam++;
    char cont = 0,i=0;
    for(i=0;i<tam;i++)
    {
        if(mensaje[i]=='a' || mensaje[i]=='e' ||
           mensaje[i]=='i' || mensaje[i]=='o' ||
           mensaje[i]=='u' || mensaje[i]=='A' ||
           mensaje[i]=='E' || mensaje[i]=='I' ||
           mensaje[i]=='O' || mensaje[i]=='U')
                cont++;
    }
    return(cont);
}
char primo(int numero)
{
    int mit=numero/2;
    int i = 0;
    for(i=2;i<=mit;i++)
    {
        if(numero%i==0) return(NO_ES_PRIMO);
    }
    return(ES_PRIMO);
}

void mandar_seq(char seq[])
{
    char tam=0;
    while(seq[tam]!=0) tam++;
    char i=0;
    for(i=0;i<tam;i++)
    {
        LATB =seq[i];
    }
}
