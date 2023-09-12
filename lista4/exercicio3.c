#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*
Autor: Ana Carolina Fuentes
*/
/*
3) Faça um algoritmo e o programa em C para ler o ano de nascimento de uma pessoa, calcular a
sua idade e verificar e informar se ela tem idade de votar (16 anos ou mais) e para obter carteira
de habilitação (18 anos ou mais). Imprimir com mensagens correspondentes.
*/
bool verificaVoto(int *idade);
bool verificaCNH(int *idade);

int main(){

    int idade = 17;
    int dia = 12;
    int mes = 7;
    int ano_nascimento = 2004;
    int *pIdade = &idade;

    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);

    /*printf("\nDigite o dia do seu nascimento: ");
    scanf("%d", &dia);
    printf("\nDigite o mes do seu nascimento: ");
    scanf("%d", &mes);
    printf("\nDigite o ano do seu nascimento: ");
    scanf("%d", &ano_nascimento);
    */
    
    if((mes <= (data_hora_atual->tm_mon+1)) && (dia < (data_hora_atual->tm_mday))){      
            *pIdade = (((data_hora_atual->tm_year+1900) - ano_nascimento) - 1);
            printf("%d", *pIdade);
    } else {
        *pIdade = ((data_hora_atual->tm_year+1900) - ano_nascimento);
        printf("%d", *pIdade);
    }



    if(verificaVoto(pIdade) == true){
        printf("\nPode votar!");
    } else {
        printf("\nAinda nao pode votar!");
    }
    if(verificaCNH(pIdade) == true){
        printf("\nPode obter a CNH!");
    } else {
        printf("\nAinda nao pode obter a CNH!");
    }

    return 0;
}

bool verificaVoto(int *idade){
    if((*idade) >= 16){
        return true;
    }else{
        return false;
    }
}

bool verificaCNH(int *idade){
    if((*idade) >= 18){
        return true;
    }else{
        return false;
    }
}
//corrigir