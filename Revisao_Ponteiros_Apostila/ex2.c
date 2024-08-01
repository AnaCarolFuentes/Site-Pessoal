#include <stdio.h>
#include <stdlib.h>

/*
Autor: Ana Carolina Fuentes

Escreva um programa que leia dois valores inteiros e
que use a função void trocar( int *n1, int *n2 ) , implementada por você, para
trocar o valor de uma variável com a outra. Ao final, apresente a ordem original e os
valores invertidos.

*/
void trocar( int *, int * );

int main()
{
    int n1 = 5; 
    int n2 = 2;
    
    printf("n1 = %d\n", n1);
    printf("n2 = %d\n", n2);

    trocar(&n1, &n2);
}

void trocar( int * n1, int * n2)
{
    *n1 = *n1 + (*n2); // n1 = 3
    *n2 = *n1 - (*n2); //n2 = 1
    *n1 = *n1 - (*n2); //n1 = 2
    printf("n1 = %d\n", *n1);
    printf("n2 = %d\n", *n2);
}