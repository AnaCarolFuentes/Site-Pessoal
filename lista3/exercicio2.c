#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Fazer um algoritmo para ler dois valores correspondentes aos lados de um retângulo, calcular
a área, o perímetro e a diagonal da figura e mostrar os valores lidos e os calculados com respectivas
mensagens.*/

float area (float, float);
float perimetro (float, float);
float diagonal (float, float);

int main(){

    float lado1, lado2;

    printf("Digite o valor do lado 1: ");
    scanf("%f", &lado1);

    printf("Digite o valor do lado 2: ");
    scanf("%f", &lado2);

    printf("A area eh: %.2f\n", area(lado1, lado2));
    printf("O perimetro eh: %.2f\n", perimetro(lado1, lado2));
    printf("A diagonal eh: %.2f\n", diagonal(lado1, lado2));

    return 0;
}

float area (float lado1, float lado2){
    return lado1 * lado2;
}

float perimetro (float lado1, float lado2){
    return lado1 + lado2;
}

float diagonal (float lado1, float lado2){
    return sqrt(pow(lado1, 2) + pow(lado2, 2));
}
