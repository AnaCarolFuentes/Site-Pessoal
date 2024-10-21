#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n = 0;
    float aux = 0.0;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &n);

    float A[n][n];
    float b[n];
    float x[n];

    printf("Digite a matriz dos coeficientes:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
        }
    }

    printf("\nDigite o vetor dos termos independentes:\n");
    
    for(int i = 0; i < n; i++)
    {
        printf("b[%d]: ", i + 1);
        scanf("%f", &b[i]);
    }

    for(int i = n - 1; i >= 0; i--)
    {
        aux = 0;
        for(int j = i + 1; j < n; j++)
        {
            aux += (A[i][j] * x[j]);
        }
        x[i] = (b[i] - aux)/(float)A[i][i];
    }

    //imprime resultado na forma vetorial
    printf("\n------RESPOSTA-------\n");
    for(int i = 0; i < n; i++)
    {
        printf("x[%d] = %.2f\n", i + 1, x[i]);
    }

}