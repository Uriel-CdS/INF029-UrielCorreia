#include <stdio.h>

#define TAM_CPF 15
#define TAM_NAME 100
#define TAM_COD 10

typedef struct Disciplina{
    int semestre;
    char nome[TAM_NAME], professor[TAM_NAME], codigo[TAM_COD];
} Disciplina;

void cadastro_disciplinas(Disciplina **disciplina, int *idx){

    (*disciplina) = realloc((*disciplina), (*idx + 1) * sizeof(Disciplina));

    if(*disciplina == NULL){
        printf("Erro ao alocar memoria!");
        return 1;
    }

    printf("\nInfore os seguintes dados da (*disciplina)\n");

    printf(">>Nome: ");
    scanf(" %[^\n]s", &(*disciplina)[*idx].nome);

    printf(">>Codigo: ");
    scanf(" %[^\n]s", &(*disciplina)[*idx].codigo);

    printf(">>Semestre: ");
    scanf("%d", &(*disciplina)[*idx].semestre);

    printf(">>Professor: ");
    scanf(" %[^\n]s", &(*disciplina)[*idx].professor);

    *idx++;
}