#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Exercício 8.4 (KING, 2008): Escreva um programa que leia um valor inteiro que
representa o dia de um ano (1 a 365) e o ano em si. Não há necessidade de verificar se
o dia do ano fornecido está no intervalo correto. A partir desses dados, o programa
deve calcular qual é o mês e o dia do mês que correspondem ao dia do ano fornecido,
lembrando que um ano bissexto é todo o ano que é divisível por 400 ou por 4, mas
não por 100. Para isso, implemente e utilize as funções:

void decompoeData( int diaDoAno, int ano, int *mes, int *dia )
bool ehBissexto( int ano )

Question: Is there a method to otimizate the memory?
*/
void decompoeData (int, int, int *, int *);
bool ehBissexto (int );

int main()
{
    int days = 0;
    int year = 0;
    int mes = 0; 
    int dia = 0;

    printf("Type the days of a year: ");
    scanf("%d", &days);
    printf("Type the year: ");
    scanf("%d", &year);

    decompoeData(days, year, &mes, &dia);
    printf("%d/%d/%d\n", dia, mes, year);
}

void decompoeData (int diaDoAno, int ano, int *mes, int *dia)
{
    if(ehBissexto(ano) == true)
    {
        if(diaDoAno <= 31)
        {
            *mes = 1;
            *dia = diaDoAno;
        } 
        else if(diaDoAno > 31 && diaDoAno <= 60)
        {
            *mes = 2;
            *dia = diaDoAno - 31;
        }
        else if(diaDoAno > 60 && diaDoAno <= 91)
        {
            *mes = 3;
            *dia = diaDoAno - 60;
        }
        else if(diaDoAno > 91 && diaDoAno <= 121)
        {
            *mes = 4;
            *dia = diaDoAno - 91;
        }
        else if(diaDoAno > 121 && diaDoAno <= 152)
        {
            *mes = 5;
            *dia = diaDoAno - 121;
        }
        else if(diaDoAno > 152 && diaDoAno <= 182)
        {
            *mes = 6;
            *dia = diaDoAno - 152;
        }
        else if(diaDoAno > 182 && diaDoAno <= 213)
        {
            *mes = 7;
            *dia = diaDoAno - 182;
        }
        else if(diaDoAno > 213 && diaDoAno <= 244)
        {
            *mes = 8;
            *dia = diaDoAno - 213;
        }
        else if(diaDoAno > 244 && diaDoAno <= 274)
        {
            *mes = 9;
            *dia = diaDoAno - 244;
        }
        else if(diaDoAno > 274 && diaDoAno <= 305)
        {
            *mes = 10;
            *dia = diaDoAno - 274;
        }
        else if(diaDoAno > 305 && diaDoAno <= 335)
        {
            *mes = 11;
            *dia = diaDoAno - 305;
        }
        else if(diaDoAno > 335 && diaDoAno <= 366)
        {
            *mes = 12;
            *dia = diaDoAno - 335;
        }
        
    } 
    else
    {
         if(diaDoAno <= 31)
        {
            *mes = 1;
            *dia = diaDoAno;
        } 
        else if(diaDoAno > 31 && diaDoAno <= 59)
        {
            *mes = 2;
            *dia = diaDoAno - 31;
        }
        else if(diaDoAno > 59 && diaDoAno <= 90)
        {
            *mes = 3;
            *dia = diaDoAno - 59;
        }
        else if(diaDoAno > 90 && diaDoAno <= 120)
        {
            *mes = 4;
            *dia = diaDoAno - 90;
        }
        else if(diaDoAno > 120 && diaDoAno <= 151)
        {
            *mes = 5;
            *dia = diaDoAno - 120;
        }
        else if(diaDoAno > 151 && diaDoAno <= 181)
        {
            *mes = 6;
            *dia = diaDoAno - 151;
        }
        else if(diaDoAno > 181 && diaDoAno <= 212)
        {
            *mes = 7;
            *dia = diaDoAno - 181;
        }
        else if(diaDoAno > 212 && diaDoAno <= 243)
        {
            *mes = 8;
            *dia = diaDoAno - 212;
        }
        else if(diaDoAno > 243 && diaDoAno <= 273)
        {
            *mes = 9;
            *dia = diaDoAno - 243;
        }
        else if(diaDoAno > 273 && diaDoAno <= 304)
        {
            *mes = 10;
            *dia = diaDoAno - 273;
        }
        else if(diaDoAno > 304 && diaDoAno <= 334)
        {
            *mes = 11;
            *dia = diaDoAno - 304;
        }
        else if(diaDoAno > 334 && diaDoAno <= 365)
        {
            *mes = 12;
            *dia = diaDoAno - 334;
        }
        

    }
}
bool ehBissexto (int ano) //fevereiro tem 29 dias
{
    if(ano % 4 == 0 && ano % 100 != 0)
    {
        return true;
    } 
    else
    {
        return false;
    }
}