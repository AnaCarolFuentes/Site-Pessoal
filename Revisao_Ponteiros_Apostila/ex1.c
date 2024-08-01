#include <stdio.h>
#include <stdlib.h>

/*
Autor: Ana Carolina Fuentes

Escreva um programa que leia 10 valores decimais, calcule
o somatório e a média aritmética dos valores fornecidos e apresente o resultado. O
cálculo deve ser feito por meio da função (que você deve implementar):
void somatorioMedia( float a[], int n, float *somatorio, float *media )
*/

void somatorioMedia( float [], int , float *, float * );

int main()
{
    float valor[10];
    float soma = 0.0;
    float media = 0.0;

    //ler valores do array
    for(int i = 0; i < 10; i++)
    {
        printf("n[%d]: ", i);
        scanf("%f", (valor + i));
    }

    somatorioMedia(valor, 10, &soma, &media);


}

void somatorioMedia(float valor[], int n, float * somatorio, float * media )
{
     for(int i = 0; i < n; i++)
    {
        printf("n[%d]: %.2f\n", i, *(valor + i));
    }
    for(int i = 0; i < n; i++)
    {
        *somatorio = *somatorio + (*(valor + i));
    }
    *media = (*somatorio)/n;
    printf("Soma = %.2f\n", *somatorio);
    printf("Media = %.2f\n", *media);
    
}