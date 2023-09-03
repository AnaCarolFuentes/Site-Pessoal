#include <stdio.h>
#include <stdlib.h>


int main(){
    /*3) Crie um arquivo Exercicio3.c e dentro do arquivo crie a função main. Usando a estru-
tura de repetição do...while exibir os números que terminam com o algarismo 5 começando
em 100 indo até -100.*/

    int num = 100;

    do{
        if(((num % 10) == 5) || ((num % 10) == -5)){
            printf("%d, ", num);
        }
        num--;
    } while (num >= -100);



    return 0;
}