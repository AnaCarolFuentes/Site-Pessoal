#include <stdio.h>
#include <stdlib.h>

#define l1 2
#define c1 2
#define l2 2
#define c2 2

int soma(int a, int b);

int main()
{
    int m1[l1][c1] = 
    {
        {1, 2},
        {3, 4}
    };

    int m2[l2][c2] = 
    {
        {3, 4},
        {5, 1}
    };

    int mSoma [l1][c1];
    /* Soma m1 e m2*/

    if(l1 == l2 && c1 == c2)
    {
        for(int i = 0; i < l1; i++)
        {
            for(int j = 0; j < c1; j++)
            {
                mSoma[i][j] = soma(m1[i][j], m2[i][j]);
            }
        }
    }

    /*Exibe Matriz*/
    for(int i = 0; i < l1; i++)
        {
            for(int j = 0; j < c1; j++)
            {
                printf("%d ", mSoma[i][j]);
            }
            printf("\n");
        }

}

int soma(int a, int b)
{
    return a + b;
}