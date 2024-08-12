#include <stdio.h>
#include <stdlib.h>

/*
Exercício 8.3 (KING, 2008): Escreva um programa que leia um valor inteiro que
representa uma quantidade de tempo em segundos e que obtenha a quantidade de
horas, minutos e segundos contidos nessa quantidade original. O cálculo deve ser
feito por meio da função (que você deve implementar):
void decompoeTempo( int totalSeg, int *horas, int *minutos, int *seg )
*/
void decompoeTempo( int, int *, int *, int * );

int main()
{
    int time_second = 0;
    int horas = 0;
    int minutos = 0;
    int segundos = 0; 


    printf("Digite o tempo em segundos: ");
    scanf("%d", &time_second);
    decompoeTempo(time_second, &horas, &minutos, &segundos);

    printf("%d:%d:%d\n", horas, minutos, segundos);
}

void decompoeTempo( int totalSeg, int * horas, int * minutos, int * seg )
{
    while (totalSeg >= 3600)
    {
        (*horas)++;
        totalSeg -= 3600;
    }
    while (totalSeg >= 60)
    {
        (*minutos)++;
        totalSeg -= 60;
    }
    *seg = totalSeg;
    
}