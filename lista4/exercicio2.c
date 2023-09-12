#include <stdio.h>
#include <stdlib.h>

/*
Autor do arquivo: Ana Carolina Fuentes
*/
/*
2) Fazer um algoritmo e o programa em C para ler 3 números e mostrá-los em ordem crescente.
*/

int main(){
    
    int vetor[3];

    printf("Digite o primeiro numero: ");
    scanf("%d", &vetor[0]);
    printf("Digite o segundo numero: ");
    scanf("%d", &vetor[1]);
    printf("Digite o terceiro numero: ");
    scanf("%d", &vetor[2]);

   //algoritmo para a ordenacao do vetor 
    for(int i=0; i<3; i++){

        for(int j=i; j<3; j++){

            if(vetor[i] > vetor[j]){
                int swap = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = swap;
            }
        }

    }
    
    //laco para exibir os valores do vetor
    for(int i=0; i<3; i++){
        printf("%d\n", vetor[i]);
    }


}


