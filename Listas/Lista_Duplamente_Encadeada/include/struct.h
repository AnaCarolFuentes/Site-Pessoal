/*Ana Carolina Fuentes*/
#ifndef STRUCT_H
#define STRUCT_H

//structs

typedef struct produto 
{
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
    struct produto * proximo;
} Produto;

typedef struct Lista {
    Produto * inicio;
    Produto * fim;
    int quantidade;
} Lista;


#endif