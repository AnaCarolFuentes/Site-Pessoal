#include <stdio.h>

/*
Autor: Ana Carolina Fuentes
*/
/*
5) Desenvolva um algoritmo e um programa em C de uma calculadora que contém as seguintes
operações: +, -, *, / e %, utilizando:
(a) Comando se/if
(b) Comando seleção/case
*/
float soma(float *n1, float *n2);
float subtracao(float *n1, float *n2);
float multiplicacao(float *n1, float *n2);
float divisao(float *n1, float *n2);
void lerNumero(float *n1, float *n2);

int main(){

    int opcao = 1;
    float n1, n2;
    float *pn1, *pn2;
    pn1 = &n1;
    pn2 = &n2;

    do{
        printf("\n**MENU DE OPCOES**");
        printf("\n1-Soma");
        printf("\n2-Subtracao");
        printf("\n3-Multiplicação");
        printf("\n4-Divisao");
        printf("\n0-Sair");

        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: 
                lerNumero(pn1, pn2);
                printf("A soma eh %.2f", soma(pn1, pn2));
                break;
            case 2:
                lerNumero(pn1, pn2);
                printf("A subtracao eh %.2f", subtracao(pn1, pn2));
                break;
            case 3:
                lerNumero(pn1, pn2); 
                printf("A multiplicacao eh %.2f", multiplicacao(pn1, pn2));
                break;
            case 4:
                lerNumero(pn1, pn2);
                if((divisao(pn1, pn2)) == -1){
                    printf("Nao existe divisao por 0!");
                } else{
                printf("A divisao eh %.2f", divisao(pn1, pn2));
                }
                break;
            case 5:
                printf("Saindo...");
                break;
            default: 
                printf("Opcao Invalida!");
                break;
                
        }

    } while (opcao != 0);
    

    return 0;

}

float soma(float *n1, float *n2){
    return (*n1) + (*n2);
}

float subtracao(float *n1, float *n2){
    return (*n1) - (*n2);
}

float multiplicacao(float *n1, float *n2){
    return (*n1) * (*n2);
}

float divisao(float *n1, float *n2){
    if(*n2 == 0){
        return -1;
    } else
        return (*n1) / (*n2);
}

void lerNumero(float *pn1, float *pn2){
    float n1, n2;
    pn1 = &n1;
    pn2 = &n2;
    printf("Digite o primeiro numero:");
    scanf("%d", &n1);
    printf("Digite o segundo numero:");
    scanf("%d", &n2);
}

