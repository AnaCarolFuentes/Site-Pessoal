#include <stdio.h>
#include <stdlib.h>




void ordParImpar_bubble (int *vet, int tam);
void swap (int *, int *);
void imprimeLista (int * vet, int size);
void ordParImpar_copy (int *vet, int tam);
void ordParImpar_otimizado(int * vet, int tam);


int main()
{
    int vet1[8] = {1, 4, 6, 5, 9, 3, 8, 2};
    int vet2[8] = {1, 4, 6, 5, 9, 3, 8, 2};
    int vet3[8] = {1, 4, 6, 5, 9, 3, 8, 2};

    ordParImpar_bubble (vet1, 8);
    imprimeLista (vet1, 8);
    printf("----------------\n");
    ordParImpar_copy (vet2, 8);
    imprimeLista (vet2, 8);
    printf("----------------\n");
    ordParImpar_otimizado (vet3, 8);
    imprimeLista (vet3, 8);
    printf("----------------\n");

}




void ordParImpar_bubble(int *vet, int tam) //O(n²)
{
    for(int i = 0; i < tam; i++)
    {
        for(int j = tam - 1; j > i; j--)
        {
            if(vet[j - 1] % 2 == 0 && vet[j] % 2 != 0)
            {
                swap(&vet[j - 1], &vet[j]);
            }
        }
    }
}




void swap (int * a, int * b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}




void imprimeLista (int * vet, int size)
{
    printf("-------Imprimindo vet------\n");
    for(int i = 0; i < size; i++)
    {
        printf("vet[%d]: %d", i, vet[i]);
        printf("\n");
    }
}




void ordParImpar_copy (int *vet, int tam) //O(n)
{
    int auxImpar[tam];
    int auxPar[tam];
    int contImpar = 0;
    int contPar = 0;
    for(int i = 0; i < tam; i++)
    {
        if(vet[i] % 2 != 0)
        {
            auxImpar[contImpar++] = vet[i];
        } else
        {
            auxPar[contPar++] = vet[i];
        }
    }
    for(int i = 0; i < contImpar; i++)
    {
        vet[i] = auxImpar[i];
    }
    contPar = 0;
    for(int i = contImpar; i < tam; i++)
    {
        vet[i] = auxPar[contPar++];
    }
}


void ordParImpar_otimizado(int * vet, int tam)
{


    for(int i = 0; i < tam; i++)
    {
        if(vet[i] % 2 == 0)
        {
            for(int j = tam - 1; j >= i; j--)
            {
                if(vet[j] % 2 != 0)
                {
                    swap(&vet[j], &vet[i]);
                    break;
                }
            }
        }
    }
}

