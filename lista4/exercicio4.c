#include <stdio.h>
#include <stdlib.h>

/*
Autor: Ana Carolina Fuentes
*/
/*
4) Fazer um algoritmo e o programa em C para calcular e mostrar o salário mensal de uma
pessoa, determinado pelas condições que seguem. Se o número de horas trabalhado for inferior
a 40, a pessoa recebe R$ 8,00 por hora, senão a pessoa recebe R$ 320,00 mais R$ 12,00 para
cada hora trabalhada acima de 40 horas. O algoritmo deve pedir o número de horas trabalhadas
e deve dar o salário como saída, com respectiva mensagem.
*/
float calculaSalario(float *horas);

int main(){

    float hora = 0.0;
    float *pHora = NULL;
    pHora = &hora;

    printf("Digite o total de horas trabalhadas: ");
    scanf("%f", &hora); 
    printf("O salario recebido eh de %.2f reais\n", calculaSalario(pHora));

    return 0;
}

float calculaSalario (float *horas){

    if((*horas) < 40){
        return ((*horas) * 8);
    } else{
        return (320 + (12 * (*horas)));
    }

}

