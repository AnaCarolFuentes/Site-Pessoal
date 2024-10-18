#include <stdio.h>
#include <stdlib.h>

/*

author: Ana Carolina Fuentes
This file calculates a system using the simple Gauss method.
*/

int main()
{
    int n = 0;
    float aux = 0.0;
    float m = 0.0;

    printf("Digite a ordem da matriz: ");

    scanf("%d", &n);

    float A[n][n];
    float b[n];
    float x[n];

    printf("Digite a matriz dos coeficientes:\n");

    for(int i = 0; i < n; i++)
    {
        printf("\nLinha %d\n", i + 1); // perguntar como melhorar na hora de inserir os valores na matriz
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    printf("\nDigite o vetor dos termos independentes:\n");
    
    for(int i = 0; i < n; i++)
    {
        printf("b[%d]: ", i);
        scanf("%f", &b[i]);
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            m = (-1) * (A[j][i] / A[i][i]);
            b[j] += m * b[i];
    
            for(int k = 0; k < n; k++)
            {
                A[j][k] += m * A[i][k];
            }
        }
    }

    //Calculate the system 
    for(int i = n - 1; i >= 0; i--)
    {
        aux = 0;
        for(int j = i + 1; j < n; j++)
        {
            aux += (A[i][j] * x[j]);
        }
        x[i] = (b[i] - aux)/(float)A[i][i];
    }

    printf("\n------Forma Triangular-------\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%.3f ", A[i][j]);
            
        }
            printf(" = %.3f", b[i]);
            printf("\n");
    }


    //print the result in vector form
    printf("\n------RESPOSTA-------\n");
    for(int i = 0; i < n; i++)
    {
        printf("x[%d] = %.3f\n", i, x[i]);
    }
}