#include <stdio.h>
#include <stdlib.h>

#define l1 3
#define c1 2
#define l2 2
#define c2 3

int multiplica(int a, int b);

int main()
{
    int m1[l1][c1] = 
    {
        {1, 2},
        {3, 4},
        {5, 6},
    };

    int m2[l2][c2] = 
    {
        {3, 4, 6},
        {5, 1, 2}
    };

    int mResultante[l1][c2];

    for(int i = 0; i < l1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            for(int k = 0; k < c1; k++)
            {
                mResultante[i][k] += multiplica(m1[i][k], m2[k][j]);
            }
        }
    }
    /* Multiplica */
}

int multiplica(int a, int b)
{
    return a * b;
}