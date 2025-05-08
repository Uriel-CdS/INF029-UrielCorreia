#include <stdio.h>

#define TAM_CPF 15
#define TAM_NAME 100
#define TAM_MATR 11

typedef struct Data{
    int dia, mes, ano;
} Data;

typedef struct Professor{
    int cpf[TAM_CPF];
    char nome[TAM_NAME], matricula[TAM_MATR], sexo;
    struct Data aniversario;
} Professor;

void cadastro_professores(Professor **professor ,int *idx){

    *professor = realloc(*professor, (*idx + 1) * sizeof(*professor));

    if(*professor == NULL){
        printf("Erro ao alocar memoria!");
        return 1;
    }

    printf("\nInforme os seguintes dados do *professor\n");
    printf(">>Nome: ");
    scanf(" %[^\n]s", &(*professor)[*idx].nome);
    
    printf(">>CPF: ");
    scanf("%d", &(*professor)[*idx].cpf);

    printf(">>Matrícula: ");
    scanf(" %[^\n]s", &(*professor)[*idx].matricula);

    printf(">>Sexo (m/f): ");
    scanf("%s", &(*professor)[*idx].sexo);

    printf(">>Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &(*professor)[*idx].aniversario.dia, 
                      &(*professor)[*idx].aniversario.mes, 
                      &(*professor)[*idx].aniversario.ano);
    
    *idx++;
}