
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
* Autora: Ana Carolina Fuentes
*/

/*A Lanchonete Come Aqui, Tomba Ali possui, em seu cardápio, apenas 3 itens (hamburguer,
refrigerante e batata frita). Fazer um algoritmo para ler o nome e a quantidade de itens pedidos
por um cliente (sabendo que o hamburguer custa R$ 2,00, o refrigerante custa R$ 1,00 e a batata
frita R$ 0,50). O algoritmo deve calcular o valor total do pedido e emitir uma nota fiscal da
seguinte maneira:*/

float custoTotal(float, float, float);

int main(){

    //declaracao de variaveis
    char nome[20] = {"\0"};
    unsigned int quantidade = 0;
    unsigned int cont_hamburguer = 0;
    unsigned int cont_refri = 0;
    unsigned int cont_batata = 0;
    float custo = 0.0;
    unsigned int opcao = 0;
    char resposta[3] = {"\0"};
    bool continuar = true;
    
                //laço para mostrar o menu de opcoes ao cliente
                while(continuar == true){

                    printf("\nCARDAPIO");
                    printf("\nHamburguer - 2 reais");
                    printf("\nRefrigerante - 1 real");
                    printf("\nBatata - 50 centavos");
                    printf("\nDigite o nome do produto desejado: ");
                    scanf("%s", nome);
                    printf("Digite a quantidade:");
                    scanf("%d", &quantidade);
                    
                    if(strcmpi("hamburguer", nome) == 0) {
                        cont_hamburguer++;
                        custo+= quantidade * 2;
                    } 
                    else if(strcmpi("refrigerante", nome) == 0)
                    {
                        cont_refri++;
                        custo+= quantidade * 1;
                    }
                    else if(strcmpi("batata", nome) == 0)
                    {
                        cont_batata++;
                        custo+= quantidade * 0.5;
                    }

                    printf("\nDeseja continuar o pedido? ");
                    scanf("%s", resposta);

                    //compara a resposta do cliente
                    if(strcmpi("sim", resposta) == 0)
                    {
                        continuar = true;
                    } 
                    else
                    {
                        continuar = false;
                    }
                }
                //emite o valor total da compra do cliente
                printf("\n**NOTA FISCAL**");
                printf("\nHamburguer: %d --> %d reais", cont_hamburguer, cont_hamburguer * 2);
                printf("\nRefrigerante: %d --> %d reais", cont_refri, cont_refri);
                printf("\nBatata frita: %d --> %.2f reais", cont_batata, (cont_batata * 0.5));
                printf("\nValor total: %.2f reais", custo);

    return 0;
  } 