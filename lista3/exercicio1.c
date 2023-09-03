
#include <stdio.h>
#include <stdlib.h>


/*Fazer um algoritmo para receber dois valores numéricos do tipo inteiro e calcular a soma
dos dois números. O algoritmo deve mostrar os dois valores lidos e o resultado da operação com
respectivas mensagens.*/

//Prototipo da funcao para calcular a soma
int soma(int, int);

int main(){

    int n1, n2;

    printf("Digite um numero: ");
    scanf("%d", &n1);
    printf("Digite outro numero: ");    
    scanf("%d", &n2);

    printf("Primeiro numero: %d\n", n1);
    printf("Segundo numero: %d\n", n2);
    printf("A soma dos dois numeros eh: %d\n", soma(n1, n2));
}

int soma(int n1, int n2){
    return n1 + n2;
}