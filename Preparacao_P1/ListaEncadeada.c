#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct pessoa
{
    char nome[30];
    int idade;
    struct pessoa * proxima;
} Pessoa;

typedef struct lista
{
    Pessoa * inicio;
    int tamanho;
} Lista;

Pessoa * LerDadosNovaPessoa ();
void insereNaLista (Lista *, Pessoa *);
void imprimeLista(Lista *);
bool checaListaVazia (Lista *);
void mensagem(char[]);
void bubble (Lista *, int);
void opcoesOrdenacao ();



int main()
{
    Lista lista;
    lista.inicio = NULL;
    lista.tamanho = 0;
    int opcao = 1;

    do
    {
        printf("---MENU OPCOES---\n");
        printf("1 -> Inserir Pessoa na Lista\n");
        printf("2 -> Imprimir Lista\n");
        printf("3 -> Ordenar Lista em ordem Alfabetica\n");
        printf("0 -> Sair\n");
        printf("-----------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);


        switch (opcao)
        {
        case 1:
            insereNaLista(&lista, LerDadosNovaPessoa());
            break;
        case 2:
            imprimeLista(&lista);
            break;
        case 3:
            opcoesOrdenacao(&lista);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            break;
        }

    } while(opcao != 0);
}

Pessoa * LerDadosNovaPessoa ()
{
    Pessoa * novaPessoa = (Pessoa*) malloc(sizeof(Pessoa));

    printf("Digite seu nome: ");
    scanf("%s", novaPessoa->nome);
    printf("Digite sua idade: ");
    scanf("%d", &novaPessoa->idade);

    novaPessoa->proxima = NULL;

    return novaPessoa;
}

void insereNaLista (Lista * lista, Pessoa * novaPessoa)
{
    Pessoa * aux = lista->inicio;
    lista->inicio = novaPessoa;
    novaPessoa->proxima = aux;
    lista->tamanho++;
}

void imprimeLista(Lista * lista)
{
    if(checaListaVazia(lista) == true)
        mensagem("imprimir");
    else
    {
        Pessoa * aux = lista->inicio;
        int contador = 1;
        do
        {
            printf("-------------Pessoa %d-----------\n", contador);
            printf("Nome: %s\n", aux->nome);
            printf("Idade: %d\n", aux->idade);
            printf("---------------------------------\n");
            aux = aux->proxima;
            contador++;
        } while(aux != NULL);
    }
}

bool checaListaVazia(Lista *lista)
{
    return lista->inicio == NULL;
}

void mensagem(char mensagem[])
{
        printf("\nNao eh possivel %s nenhuma Pessoa, pois a Lista esta vazia!\n", mensagem);
}

void opcoesOrdenacao (Lista * lista)

{
    int metodo = 1;
            do{
                printf("---MENU OPCOES---\n");
                printf("1 -> Bubble\n");
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
                    bubble(lista, lista->tamanho);
                    break;
                
                default:
                    break;
                }
            } while (metodo != -1);        
}

void bubble (Lista * lista, int tamanho)
{
    int i = 0; 
    int troca;
    Pessoa * pessoa = lista->inicio;
    Pessoa * aux = lista->inicio;
    Pessoa * swap;

    while(i < tamanho && troca == 1)
    {
        troca = 0;
        do
        {
            if(strcmp(pessoa->nome, pessoa->proxima->nome) > 0)
            {
                troca = 1;
                swap = pessoa;
                pessoa = pessoa->proxima;
                pessoa->proxima = swap;
                aux = aux->proxima;
            }
        } while(aux != NULL);
            
       printf("Ordenou!\n"); 
    }
}