#include <stdio.h>

#define TAM_CPF 15
#define TAM_NAME 100
#define TAM_MATR 11

typedef struct Data{
    int dia, mes, ano;
} Data;

typedef struct Aluno{
    char nome[TAM_NAME], cpf[TAM_CPF], matricula[TAM_MATR], sexo;
    struct Data aniversario;
} Aluno;

void cadastro_alunos(Aluno **aluno, int *idx){

    *aluno = realloc(*aluno, (*idx + 1) * sizeof(Aluno));

    if(*aluno == NULL){
        printf("Erro ao alocar memoria!");
        return;
    }

    printf("\nInforme os seguintes dados do *aluno\n\n");

    printf(">>Nome: ");
    scanf(" %[^\n]s", &(*aluno)[*idx].nome);
    
    printf(">>CPF: ");
    scanf(" %[^\n]s", &(*aluno)[*idx].cpf);

    printf(">>Matrícula: ");
    scanf(" %[^\n]s", &(*aluno)[*idx].matricula);

    printf(">>Sexo (m/f): ");
    scanf("%s", &(*aluno)[*idx].sexo);

    printf(">>Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &(*aluno)[*idx].aniversario.dia, 
                      &(*aluno)[*idx].aniversario.mes, 
                      &(*aluno)[*idx].aniversario.ano);
    
    (*idx)++;
}

/*int main(){

    Aluno *alunos = NULL;
    int idx_aln = 0;
    int choose = 1;

    while(choose){

        scanf("%d", &choose);

        switch (choose){
            case 1:{
                cadastro_alunos(&alunos, &idx_aln);
                break;
            }case 2:{
                for(int i = 0; i < idx_aln; i++){
                    printf("Nome: %s\n", alunos[i].nome);
                }
            }
            default:
                break;
        }
    }

    return 0;
}*/