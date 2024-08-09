#include "funcoes.h"
#include "struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Protótipo das funções
int inicializarLista(Lista *);
int imprimirLista(Lista *);
void mensagem(char *);





int inicializarLista (Lista * lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;
    return 1;
}

int imprimirLista(Lista * lista)
{
    if(lista->inicio == NULL)
    {
        mensagem("imprimir");
        return 0;
    }

    Produto * aux = lista->inicio;
    while(aux != NULL)
    {
        printf("-----------------------------\n");
        printf("Codigo: %d\n", aux->codigo);
        printf("Nome: %s\n", aux->nome);
        printf("Quantidade: %d\n", aux->quantidade);
        printf("Preco: R$ %.2f\n", aux->preco);
        printf("-----------------------------\n");
        
        aux = aux->proximo;
    }
    return 1;

}

void mensagem(char * mensagem)
{
    printf("Nao foi possivel %s na lista, pois ela esta vazia\n", mensagem);
}





