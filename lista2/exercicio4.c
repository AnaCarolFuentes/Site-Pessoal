#include <stdio.h>
#include <stdlib.h>

int main(){
    /*4) Crie um arquivo Exercicio4.c e dentro do arquivo crie a função main. Usando alguma
estrutura de repetição some os valores ímpares de 1 a 9 e exiba o valor final da soma.*/
    int soma = 0;

    for(int i=0; i<10; i++){
        if((i % 2) != 0){
            soma += i;
        }
    }

    printf("Soma = %d", soma);

}