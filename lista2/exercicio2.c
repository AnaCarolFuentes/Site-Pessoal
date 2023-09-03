#include <stdio.h>
#include <stdlib.h>

int main(){

    /*2) Crie um arquivo Exercicio2.c e dentro do arquivo crie a função main. Usando a
estrutura de repetição while exibir os múltiplos de 100 até o valor 1000.*/
    int num = 1;

    while (num <= 1000)
    {
        if((num % 100) == 0){
            printf("\n%d eh multiplo de 100", num);
        }
            num++;
    }

    return 0;


}