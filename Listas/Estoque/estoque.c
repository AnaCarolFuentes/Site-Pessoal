/*
Ana Carolina Fuentes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto 
{
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
    struct produto * proximo;
    struct produto * anterior;
} Produto;

typedef struct Lista {
    Produto * inicio;
    Produto * fim;
    int quantidade;
} Lista;

//Protótipo das funções
int inicializarLista(Lista *);
int imprimirLista(Lista *);
void mensagemListaVazia(char *);
void mensagemValida(char *, int);
Produto * novoProduto ();
void lerDadosProduto (Produto *);
int adicionarProdutoInicio(Lista *, Produto *);
int adicionarProdutoFim(Lista *, Produto *);
int adicionarProdutoMeio(Lista *, Produto *, int);
int removerProduto(Lista *, int);
int atualizarQuantidade (Lista *, int, int);

int main()
{
    Lista estoque;
    inicializarLista(&estoque);
    int opcao = 1;

    //Menu opcoes
    do
    {
        int posicao;
        int retorno;
        int codigo;
        int quantidade;

        printf("------GERENCIAMENTO DE ESTOQUE-----\n");
        printf("1 - Adicionar produto no Inicio do Estoque\n");
        printf("2 - Adicionar produto no Fim do Estoque\n");
        printf("3 - Adicionar produto em uma posicao especifica do Estoque\n");
        printf("4 - Remover produto do Estoque\n");
        printf("5 - Atualizar quantidade do produto\n");
        printf("6 - Imprimir produtos do Estoque\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);
        if(opcao == 0)
            break;

        switch (opcao)
        {
        case 1:
            retorno = adicionarProdutoInicio(&estoque, novoProduto());
            mensagemValida("adicionar", retorno);
            break;
            
        case 2:
            retorno = adicionarProdutoFim(&estoque, novoProduto());
            mensagemValida("adicionar", retorno);
            break;

        case 3:
            printf("Digite a posicao desejada: ");
            scanf("%d", &posicao);
            if(posicao > estoque.quantidade || posicao < 1)
            {
                printf("Posicao invalida!\n");
                break;
            }
            retorno = adicionarProdutoMeio(&estoque, novoProduto(), posicao);
            mensagemValida("adicionar", retorno);
            break;

        case 5:
            printf("Digite o codigo do produto que deseja alterar a quantidade: ");
            scanf("%d", &codigo);
            printf("Digite a nova quantidade: ");
            scanf("%d", &quantidade);

            retorno = atualizarQuantidade(&estoque, codigo, quantidade);

            if(retorno == 1) 
                mensagemValida("atualizar quantidade do", retorno);
            else if(retorno == 0)
                printf("Codigo do produto nao encontrado!\n");
            break;

        case 6:
            imprimirLista(&estoque);
            break;
        
        default:
            break;
        }
    } while (opcao != 0);
    
}


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
        mensagemListaVazia("imprimir");
        return -1;
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

void mensagemListaVazia(char * mensagem)
{
    printf("Nao foi possivel %s na lista, pois ela esta vazia\n", mensagem);
}

Produto * novoProduto ()
{
    Produto * novoProduto = (Produto*) malloc (sizeof(Produto));

    if(novoProduto == NULL)
        return NULL;
    
    novoProduto->proximo = NULL;
    novoProduto->anterior = NULL;

    lerDadosProduto (novoProduto);
    return novoProduto;
}

void lerDadosProduto (Produto * produto)
{
    int codigo, quantidade;
    char nome[50];
    float preco;
    printf("------CADASTRAR NOVO PRODUTO------\n");
    printf("Digite o codigo do produto:");
    scanf("%d", &codigo);
    produto->codigo = codigo;

    printf("Digite o nome do produto:");
    scanf("%s", nome);
    strcpy(produto->nome, nome);

    printf("Digite a quantidade do produto:");
    scanf("%d", &quantidade);
    produto->quantidade = quantidade;

    printf("Digite o preco do produto:");
    scanf("%f", &preco);
    produto->preco = preco;

    printf("-------------------------\n");
}

int adicionarProdutoInicio(Lista * lista, Produto * produto)
{
    if(lista->inicio == NULL)
    {
        lista->inicio = produto;
        lista->fim = produto;
    }
    else 
    {
        produto->proximo = lista->inicio;
        lista->inicio->anterior = produto;
        lista->inicio = produto;
    }

    lista->quantidade++;
    return 1;
}

int adicionarProdutoFim(Lista * lista, Produto * produto)
{
    if(lista->inicio == NULL)
    {
        lista->inicio = produto;
        lista->fim = produto;
    }
    else
    {
        lista->fim->proximo = produto;
        produto->anterior = lista->fim;
        lista->fim = produto;
    }
    lista->quantidade++;
    return 1;
}

int adicionarProdutoMeio(Lista * lista, Produto * produto, int posicao)
{
    if(lista->inicio == NULL)
    {
        lista->inicio = produto;
        lista->fim = produto;
    }
    else if (posicao == 1)
    {
        produto->proximo = lista->inicio;
        lista->inicio->anterior = produto;
        lista->inicio = produto;
    }
    else
    {
        int i = 0;
        Produto * aux = lista->inicio;

        for(i = 1; i < posicao - 1 && aux->proximo != NULL; i++)
        {
            aux = aux->proximo;
        }

        produto->proximo = aux->proximo;
        produto->anterior = aux;

        if(aux->proximo != NULL)
            aux->proximo->anterior = produto;
        else  
            lista->fim = produto;
        
        aux->proximo = produto;
    }
    lista->quantidade++;
    return 1;
}

void mensagemValida(char * mensagem, int retorno)
{
    if(retorno == 1)
        printf("Secesso ao %s produto no estoque!\n", mensagem);
    else
        printf("Falha ao %s produto no estoque\n", mensagem);
}

int atualizarQuantidade (Lista * lista, int codigo, int novaQuantidade)
{
    if(lista->inicio == NULL)
    {
        mensagemListaVazia("atualizar quantidade");
        return -1;
    }

    Produto * aux = lista->inicio;
    int encontrou = 0;

    while(aux != NULL)
    {
        if(aux->codigo == codigo)
        {
            aux->quantidade = novaQuantidade;
            encontrou = 1;
            break;
        }
        aux = aux->proximo;
    }

    return (encontrou == 1) ? 1 : 0;
}
