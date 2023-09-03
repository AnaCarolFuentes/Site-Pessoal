#include <stdio.h>
#include <stdlib.h>

int main(){
    /*Crie um arquivo Exercicio5.c e dentro do arquivo crie a função main. Usando alguma
estrutura de repetição imprima o 10o
valor da sequencia de Fibonacci. O valor do 2o elemento da sequência de Fibonacci é dado pela soma do 1o
e do 0o
, onde:*/

    int soma = 0; 

    for(int i=0; i<10; i++){
        soma += i;
    }

    printf("10° Fibonacci = %d", soma);

}