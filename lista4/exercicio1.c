#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Autor do arquivo: Ana Carolina Fuentes
*
/*
1) Fazer um algoritmo e o programa em C para ler o nome e o salário anual de um trabalha-
dor. Este trabalhador deve pagar 10% de imposto se o seu salário anual for menor ou igual a
R$ 12.000,00. Caso o salário seja maior que este valor, o imposto devido é igual a 10% sobre
R$ 12.000,00 mais 25% sobre o que passar de R$ 12.000,00. Calcular o imposto devido pelo
trabalhador e imprimir com mensagens correspondentes.
*/
float CalculaImposto (float salario);

int main(){

    float salario;
    char nome[50];

    printf("Digite o nome do trabalhador: ");
    scanf("%s", nome);
    printf("Digite o salario do trabalhador: ");
    scanf("%f", &salario);
    printf("Imposto: %.2f\n", CalculaImposto(salario));

    return 0;
}

//funcao para calcular e retornar o valor do imposto
float CalculaImposto (float salario){
 if(salario <= 12000){
    return 0.1 * salario;
 } 
 else if (salario > 12000){
    return (0.1 * salario) + (0.25 * (salario - 12000));
 }
}