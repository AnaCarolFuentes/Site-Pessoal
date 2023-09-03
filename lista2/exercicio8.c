#include <stdio.h>
#include <stdlib.h>

int main(){

    int valor = 0;
    int valorNovo = 0;
    int cont = 0;

    printf("Digite um valor: ");
    scanf("%d", &valor);
    

    do{
        valorNovo = (valor/10);
        cont++;
        valor = valorNovo;
   }  while(valorNovo != 0);

    printf("\n%d", cont);
}