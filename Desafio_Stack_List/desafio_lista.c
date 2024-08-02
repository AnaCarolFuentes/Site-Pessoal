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
    Node * inicio;
    Node * fim;
    int tam;
   
}List;

typedef struct stack
{
    struct stack * proximo;
    Node * dado;
    int tam;

} Stack;

int insereNode (Stack * stack, Node * node);
int insereNaLista (List * list, int dado);
int inicializaPilha(Stack * stack);
int inicializaLista (List * list);
int InsereNaPilha  (List * list, Stack * stack);
int imprimeLista (List * list);
int imprimePilha (Stack * stack);
List * concatena (List * list1, List * list2);
Node * achaIntersecao (Stack * stack1, Stack * stack2);
Node * topoPilha (Stack * stack);
int popStack(Stack * stack);

int main()
{

    Stack pilha1;
    Stack pilha2;
    List lista1;
    List lista2;
    List lista_aux;

    //Inicializa todas as estruturas criadas
    inicializaLista(&lista1);
    inicializaLista(&lista2);
    inicializaLista(&lista_aux);
    inicializaPilha(&pilha1);
    inicializaPilha(&pilha2);

    //Insere elementos na lista 1
    insereNaLista(&lista1, 1);
    insereNaLista(&lista1, 2);
    insereNaLista(&lista1, 3);

    //Insere elementos em uma lista auxiliar para criar a interseção 
    insereNaLista(&lista_aux, 7);
    insereNaLista(&lista_aux, 5);
    insereNaLista(&lista_aux, 10);

    //Concatena a lista 1 e a lista auxiliar
    concatena(&lista1, &lista_aux);

    //Imprime lista 1
    printf("-------Lista 1----------\n");
    imprimeLista(&lista1);
    getchar();

     //Insere elementos na lista 2
    insereNaLista(&lista2, 50);
    insereNaLista(&lista2, 20);

    //Concatena a lista 2 e a lista auxiliar
    concatena(&lista2, &lista_aux);

    //Imprime lista 2
    printf("-------Lista 2----------\n");
    imprimeLista(&lista2);
    getchar();

    //Insere elementos da lista 1 na pilha 1
    InsereNaPilha (&lista1, &pilha1);

    //Imprime pilha 1
    printf("-------Pilha 1----------\n");
    imprimePilha(&pilha1);
    getchar();

    //Insere elementos da lista 2 na pilha 2
    InsereNaPilha (&lista2, &pilha2);

    //Imprime pilha 2
    printf("-------Pilha 2----------\n");
    imprimePilha(&pilha2);
    getchar();

    //Exibe a interseção entre as duas listas
    printf("-------------------------------\n");
    printf("Intersecao: %x\n", achaIntersecao(&pilha1, &pilha2));

   return 0;
}

int insereNode (Stack * stack, Node * node)
{
    Stack * novo = (Stack*) malloc(sizeof(Stack));
    if(novo == NULL)
        return -1;

    novo->dado = node;
    novo->proximo = stack->proximo;
    stack->proximo = novo;
    stack->tam++;
}

int inicializaPilha(Stack * stack)
{
    stack->proximo = NULL;
    stack->tam = 0;
    return 1;
}

int inicializaLista(List * list)
{
    list->inicio = NULL;
    list->fim = NULL;
    list->tam = 0;
    return 1;
}

int insereNaLista(List * list, int dado)
{
    Node * novo = (Node*) malloc (sizeof(Node));
   
    if(novo == NULL)
        return 0;

    novo->dado = dado;
    if(list->inicio == NULL)
    {
        list->inicio = novo;
        list->fim = novo;
        novo->proximo = NULL;
        list->tam++;
    }
    else
    {
        list->fim->proximo = novo;
        list->fim = novo;
        novo->proximo = NULL;
        list->tam++;
    }
    return 1;
}

int InsereNaPilha (List * list, Stack * stack)
{
    Node * aux = list->inicio;
    if(aux == NULL)
        return 0;

    while(aux != NULL)
    {
        insereNode(stack, aux);
        aux = aux->proximo;
    }

}

Node * topoPilha (Stack * stack)
{
    if(stack->proximo == NULL)
        return NULL;

    Stack * aux = stack->proximo;
    return aux->dado;
}

int imprimeLista (List * list)
{
    if(list->inicio == NULL)
        return 0;

    Node * aux = list->inicio;
    int cont = 1;
    printf("\n----------Imprimindo Lista------------\n");
    while(aux != 0)
    {
        printf("Dado %d: %d\n", cont, aux->dado);
        cont++;
        aux = aux->proximo;
    }
    printf("\n-------------------------------------\n");
    return 1;
}

int imprimePilha (Stack * stack)
{
    if(stack->proximo == NULL)
        return 0;
    Stack * aux = stack->proximo;
   
    int cont = 1;
    printf("\n----------Imprimindo Pilha------------\n");
    while(aux != 0)
    {
        printf("Dado %d: %x\n", cont, aux->dado);
        cont++;
        aux = aux->proximo;
    }
    printf("\n-------------------------------------\n");
}

int popStack(Stack * stack)
{
    if(stack->proximo == NULL)
        return 0;

    Stack * aux = stack->proximo;
    stack->proximo = aux->proximo;
    stack->tam--;
    free(aux);
    return 1;
   
}

Node * achaIntersecao (Stack * stack1, Stack * stack2)
{
    Node * temp = NULL;

    while(topoPilha(stack1) == topoPilha(stack2))
    {
            temp = topoPilha(stack1);
            popStack(stack1);
            popStack(stack2);
    }
    return temp;

}

List * concatena (List * list1, List * list2)
{
    if(list1->inicio == NULL)
        return list2;


    if(list2->inicio == NULL)
        return list1;


    list1->fim->proximo = list2->inicio;
    list1->fim = list2->fim;
        return list1;
}




