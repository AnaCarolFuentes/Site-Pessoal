/*Ana Carolina Fuentes*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node * proximo;
    int dado;
} Node;

typedef struct 
{
   Node * fim;
   Node * inicio;
   int tam;
} Lista;

//Protótipo das funções 
int insereNoInicio (Lista *, int);
int insereNoFim (Lista *, int);
int inicializaLista (Lista *);
Lista * concatena (Lista *, Lista *);
int imprimeLista(Lista *);
Lista * separa (Lista *, int);

int main()
{

    Lista l1;

    inicializaLista(&l1);

    insereNoInicio(&l1, 1);
    insereNoInicio(&l1, 2);
    insereNoInicio(&l1, 3);
    insereNoInicio(&l1, 4);
    insereNoInicio(&l1, 5);
    insereNoInicio(&l1, 6);

    insereNoFim(&l1, 7);
    insereNoFim(&l1, 9);
    insereNoFim(&l1, 10);

    printf("\n----------Imprimindo Lista1------------\n");
    imprimeLista(&l1);
    printf("\n---------------------------------------\n");

    Lista * novaLista = separa(&l1, 4);
    printf("\n----------Imprimindo Lista1------------\n");
    imprimeLista(&l1);
    printf("\n---------------------------------------\n");
    printf("\n----------Imprimindo subconjunto de Lista 1------------\n");
    imprimeLista(novaLista);
    printf("\n---------------------------------------\n");
    
}

//Insere no inicio da lista
int insereNoInicio (Lista * lista, int dado)
{
    Node * novo = (Node*) malloc (sizeof(Node));
    
    if(novo == NULL)
        return 0;
    
    novo->dado = dado;

    if(lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->fim = novo;
        novo->proximo = NULL;
        lista->tam++;
    }
    else
    {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }

    return 1;
}

//Insere no fim da lista
int insereNoFim (Lista * lista, int dado)
{
    Node * novo = (Node*) malloc (sizeof(Node));
    
    if(novo == NULL)
        return 0;
    
    novo->dado = dado;

    if(lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->fim = novo;
        novo->proximo = NULL;
        lista->tam++;
    }
    else
    {
        lista->fim->proximo = novo;
        lista->fim = novo;
        novo->proximo = NULL;
        lista->tam++;
    }
    
    return 1;
}

//Inicializa a lista
int inicializaLista (Lista * lista)
{
    lista->inicio == NULL;
    lista->fim == NULL;
    lista->tam = 0;
    return 1;
}

//Concatena duas listas
Lista * concatena (Lista * list1, Lista * list2)
{
    if(list1->inicio == NULL)
        return list2;


    if(list2->inicio == NULL)
        return list1;


    list1->fim->proximo = list2->inicio;
    list1->fim = list2->fim;
        return list1;
}

//Separa duas listas
Lista * separa (Lista * list, int l)
{
    int i;
    int cont = 0;
    int entrou = 0;

    if(list->inicio == NULL || list->tam == 1)
    {
        return NULL;
    }

    Lista * novaLista = (Lista*) malloc (sizeof(Lista));
    Node * aux = list->inicio;
    cont++;

    while(aux->dado != l && aux != NULL)
    {
        entrou = 1;
        aux = aux->proximo;
        cont++;
    }

    if(entrou == 0)
        return NULL;

    novaLista->inicio = aux->proximo;
    novaLista->fim = list->fim;
    list->fim = aux;
    novaLista->tam = list->tam - cont;
    list->tam = cont;
    return novaLista;

}

int imprimeLista(Lista * list)
{
    int cont = 1;
    if(list->inicio == NULL)
        return 0;
    
    Node * aux = list->inicio;

    while(aux != NULL)
    {
        printf("Dado %d : %d\n", cont++, aux->dado);
        aux = aux->proximo;
    }
    return 1;
}





