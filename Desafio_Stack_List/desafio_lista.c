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

int inserirNode (Stack * stack, Node * node);
int inserirNaLista (List * list, int dado);
int inicializaPilha(Stack * stack);
int inicializaLista (List * list);
int InserirNaPilha  (List * list, Stack * stack);
int imprimeLista (List * list);
int imprimePilha (Stack * stack);
List * concatenar (List * list1, List * list2);
Node * achaIntersecao (Stack * stack1, Stack * stack2);
Node * topoPilha (Stack * stack);
int popStack(Stack * stack);

int main()
{

    Stack pilha1;
    Stack pilha2;
    List lista1;
    List lista2;
    List lista3;


    inicializaLista(&lista1);
    inicializaLista(&lista2);
    inicializaLista(&lista3);
    inicializaPilha(&pilha1);
    inicializaPilha(&pilha2);


    inserirNaLista(&lista1, 1);
    inserirNaLista(&lista1, 2);
    inserirNaLista(&lista1, 3);

    inserirNaLista(&lista3, 7);
    inserirNaLista(&lista3, 5);
    inserirNaLista(&lista3, 10);

    concatenar(&lista1, &lista3);
    printf("-------Lista 1----------\n");
    imprimeLista(&lista1);
    getchar();


    inserirNaLista(&lista2, 50);
    inserirNaLista(&lista2, 20);
    concatenar(&lista2, &lista3);
    printf("-------Lista 2----------\n");
    imprimeLista(&lista2);
    getchar();

    InserirNaPilha (&lista1, &pilha1);
    printf("-------Pilha 1----------\n");
    imprimePilha(&pilha1);
    getchar();

    InserirNaPilha (&lista2, &pilha2);
    printf("-------Pilha 2----------\n");
    imprimePilha(&pilha2);
    getchar();

    printf("-------------------------------\n");
    printf("Intersecao: %x\n", achaIntersecao(&pilha1, &pilha2));

   return 0;
}

int inserirNode (Stack * stack, Node * node)
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

int inserirNaLista(List * list, int dado)
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

int InserirNaPilha (List * list, Stack * stack)
{
    Node * aux = list->inicio;
    if(aux == NULL)
        return 0;

    while(aux != NULL)
    {
        inserirNode(stack, aux);
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

List * concatenar (List * list1, List * list2)
{
    if(list1->inicio == NULL)
        return list2;


    if(list2->inicio == NULL)
        return list1;


    list1->fim->proximo = list2->inicio;
    list1->fim = list2->fim;
        return list1;
}




