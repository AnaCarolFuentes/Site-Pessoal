#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Autor(a): Ana Carolina Fuentes
Objetivo: Criar uma struct com 10 elementos e ordená-los usando todos os métodos de ordenação
*/

#define TAM 3

typedef struct
{
    char nome[30];
    int idade;
}Pessoa;

Pessoa * criaVetorPessoa();
void imprimeLista (Pessoa *, int);
void bubble (Pessoa *, int);
void swap (Pessoa *, Pessoa *);
void opcoesOrdenacao (Pessoa *, int);

int main()
{
    Pessoa * lista;
    lista = criaVetorPessoa(lista, TAM);
    imprimeLista(lista, TAM);
    opcoesOrdenacao(lista, TAM);
}

Pessoa * criaVetorPessoa(Pessoa * lista, int size)
{
    lista = (Pessoa*) malloc (TAM * sizeof(Pessoa));
    for(int i = 0; i < size; i++)
    {
        printf("-------Posicao %d-------\n", i + 1);
        printf("Nome: ");
        scanf("%s", (lista + i)->nome);
        printf("Idade: ");
        scanf("%d", &(lista + i)->idade);
        printf("------------------------\n");
    }
    return lista;
}

void imprimeLista (Pessoa * lista, int size)
{
    printf("-------Imprimindo Lista------\n");
    for(int i = 0; i < size; i++)
    {
        printf("-------Posicao %d-------\n", i + 1);
        printf("Nome: %s\n", (lista + i)->nome);
        printf("Idade: %d\n", (lista + i)->idade);
        printf("------------------------\n");
    }
}

void bubble (Pessoa * lista, int size)
{
    int troca = 1;
    int i = 0;

    while (i < size && troca == 1)
    {
        troca = 0;
        for(int j = 0; j < TAM - 1; j++)
        {
            if(strcmp((lista + j)->nome, (lista + (j + 1))->nome) > 0)
            {
                troca = 1;
                swap((lista + j), (lista + (j + 1)));
            }
        }
        i++;
    }

}

void swap (Pessoa * p1, Pessoa * p2)
{
    Pessoa temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void opcoesOrdenacao (Pessoa * lista, int size)

{
    int metodo = 1;
            do
            {
                printf("---MENU OPCOES---\n");
                printf("1 -> Bubble Melhorado\n");
                printf("2 -> Insertion\n");
                printf("3 -> Selection\n");
                printf("4 -> Merge\n");
                printf("5 -> Quick\n");
                printf("-1 -> Sair\n");
                printf("-----------------\n");
                printf("Digite a opcao desejada: ");
                scanf("%d", &metodo);

                switch (metodo)
                {
                case 1:
                    printf("--------Bubble melhorado --------\n");
                    bubble(lista, size);
                    imprimeLista(lista, size);
                    break;
                
                default:
                    break;
                }
            } while (metodo != -1);        
}