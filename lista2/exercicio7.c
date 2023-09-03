#include <stdio.h>
#include <stdlib.h>

int main(){
    /*Crie um arquivo Exercicio7.c e dentro do arquivo crie a função main. Usando alguma
estrutura de repetição determine qual é a soma da sequência abaixo:*/

    int denominador = 0;
    float soma = 0;

    for(int i=1; i<=11; i+=2){
        denominador = 2;
        soma += (i/denominador);
        denominador+=3;
        printf("%f -", soma);
    }

    printf("Soma = %.2f", soma);

}