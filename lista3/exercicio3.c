#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Os alunos da Escola Fundamental São Jorge submetem-se a três avaliações anuais em cada
disciplina. Fazer um algoritmo para ler o nome da disciplina, o nome do aluno e as notas obtidas
nas avaliações e, em seguida, calcular a nota final do aluno, sabendo que a primeira avaliação
tem peso 2; a segunda tem peso 3 e a terceira tem peso 5. Os resultados devem ser mostrados da
seguinte maneira:*/

float notaFinal(float, float, float);

int main(){

    char nomeDisciplina[100] = {"\0"};
    char nomeAluno[100] = {"\0"};
    float nota1, nota2, nota3;

    printf("Digite o nome da disciplina: ");
    scanf("%s", nomeDisciplina);

    printf("Digite o nome do aluno: ");
    scanf("%s", nomeAluno);

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("\n**ESCOLA DE ENSINO FUNDAMENTAL SAO JORGE**\n");
    printf("Resultado final de %s\n", nomeDisciplina);
    printf("Aluno: %s\n", nomeAluno);
    printf("Nota 1: %.2f\n", nota1);
    printf("Nota 2: %.2f\n", nota2);
    printf("Nota 3: %.2f\n", nota3);
    printf("Nota final: %.2f\n", notaFinal(nota1, nota2, nota3));
}

float notaFinal (float nota1, float nota2, float nota3){
    return (((nota1 * 2) + (nota2 * 3) + (nota3 * 5)) / 10);
}

