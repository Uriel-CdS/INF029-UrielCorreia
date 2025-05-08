#include <stdio.h>
#include <stdlib.h>

#define TAM_CPF 15
#define TAM_NAME 100
#define TAM_MATR 11
#define TAM_COD 10

typedef struct Data{
    int dia, mes, ano;
} Data;

typedef struct Aluno{
    char nome[TAM_NAME], cpf[TAM_CPF], matricula[TAM_MATR], sexo;
    struct Data aniversario;
} Aluno;

typedef struct Professor{
    char nome[TAM_NAME], matricula[TAM_MATR], cpf[TAM_CPF], sexo;
    struct Data aniversario;
} Professor;


typedef struct Disciplina{
    int semestre;
    char nome[TAM_NAME], professor[TAM_NAME], codigo[TAM_COD];
} Disciplina;

void cadastro_alunos(Aluno **aluno, int *idx){

    *aluno = realloc(*aluno, (*idx + 1) * sizeof(Aluno));

    if(*aluno == NULL){
        printf("Erro ao alocar memoria!");
        return;
    }

    printf("\nInforme os seguintes dados do aluno\n\n");

    printf(">> Nome: ");
    scanf(" %[^\n]s", &(*aluno)[*idx].nome);
    
    printf(">> CPF: ");
    scanf(" %[^\n]s", &(*aluno)[*idx].cpf);

    printf(">> Matrícula: ");
    scanf(" %[^\n]s", &(*aluno)[*idx].matricula);

    printf(">> Sexo (m/f): ");
    scanf("%s", &(*aluno)[*idx].sexo);

    printf(">> Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &(*aluno)[*idx].aniversario.dia, 
                      &(*aluno)[*idx].aniversario.mes, 
                      &(*aluno)[*idx].aniversario.ano);
    
    (*idx)++;
}

void cadastro_professores(Professor **professor ,int *idx){

    *professor = realloc(*professor, (*idx + 1) * sizeof(*professor));

    if(*professor == NULL){
        printf("Erro ao alocar memoria!");
        return;
    }

    printf("\nInforme os seguintes dados do professor\n");
    printf(">> Nome: ");
    scanf(" %[^\n]s", &(*professor)[*idx].nome);
    
    printf(">> CPF: ");
    scanf("%d", &(*professor)[*idx].cpf);

    printf(">> Matrícula: ");
    scanf(" %[^\n]s", &(*professor)[*idx].matricula);

    printf(">> Sexo (m/f): ");
    scanf("%s", &(*professor)[*idx].sexo);

    printf(">> Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &(*professor)[*idx].aniversario.dia, 
                      &(*professor)[*idx].aniversario.mes, 
                      &(*professor)[*idx].aniversario.ano);
    
    (*idx)++;
}

void cadastro_disciplinas(Disciplina **disciplina, int *idx){

    (*disciplina) = realloc((*disciplina), (*idx + 1) * sizeof(Disciplina));

    if(*disciplina == NULL){
        printf("Erro ao alocar memoria!");
        return;
    }

    printf("\nInfore os seguintes dados da disciplina\n");

    printf(">> Nome: ");
    scanf(" %[^\n]s", &(*disciplina)[*idx].nome);

    printf(">> Codigo: ");
    scanf(" %[^\n]", &(*disciplina)[*idx].codigo);

    printf(">> Semestre: ");
    scanf("%d", &(*disciplina)[*idx].semestre);

    printf(">> Professor: ");
    scanf(" %[^\n]s", &(*disciplina)[*idx].professor);

    (*idx)++;
}

void relatorio(Professor *prof, int idx_prof, Aluno *al, int idx_al, Disciplina *disc, int idx_disc, int choose_relatorio){
    switch(choose_relatorio){
        case 1:{ // relatório alunos

            printf("\nRelatorio de cadastro dos alunos\n");

            for(int i = 0;i < idx_al; i++){

                printf("Cadastro n%d\n", i + 1);

                printf(">> Nome: %s\n", al[i].nome);
                printf(">> CPF: %s\n", al[i].cpf);
                printf(">> Matricula: %s\n", al[i].matricula);
                printf(">> Sexo: %c\n", al[i].sexo);
                printf(">> Data de aniversario: %02d/%02d/%02d\n\n", al[i].aniversario.dia,
                                                                   al[i].aniversario.mes,
                                                                   al[i].aniversario.ano);
            }
            break;
        }
        case 2:{ // relatório professores

            printf("\nRelatorio de cadastro de professores\n");

            for(int i = 0; i < idx_prof; i++){

                printf("Cadastro n%d\n", i + 1);

                printf(">> Nome: %s\n", prof[i].nome);
                printf(">> CPF: %s\n", prof[i].cpf);
                printf(">> Matricula: %s\n", prof[i].matricula);
                printf(">> Sexo: %c\n", prof[i].sexo);
                printf(">> Data de aniversario: %02d/%02d/%02d\n", prof[i].aniversario.dia,
                                                                   prof[i].aniversario.mes,
                                                                   prof[i].aniversario.ano);
            }

            break;
        }
        case 3:{ // relatório disciplinas

            printf("\nRelatorio de cadastro de disciplinas\n");
            
            for(int i = 0; i < idx_disc; i++){

                printf("Cadastro n%d\n", i + 1);

                printf(">> Nome: %s\n", disc[i].nome);
                printf(">> Semestre: %d\n", disc[i].semestre);
                printf(">> Professor: %s\n", disc[i].professor);
                printf(">> Codigo: %s\n", disc[i].codigo);
            }

            break;
        }
        default:{
            printf("Valor indefinido!");
            break;
        }
    }
}

void limpar_terminal(){
    system("cls");
}

int main(){

    int choose = 1;
    int idx_alu = 0, idx_prof = 0, idx_disc = 0; 
    Aluno *alunos = NULL;
    Disciplina *disciplinas = NULL;
    Professor *professores = NULL;

    while(choose){

        limpar_terminal();

        if(choose < 0 || choose > 4){
            printf("Valor invalido!");
            return 1;
        }

        printf("1 - Cadastrar alunos\n"
               "2 - Cadastrar professor\n"
               "3 - Cadastrar disciplinas\n"
               "4 - Relatorios\n"
               "0 - Sair\n");
        printf("O que deseja fazer? ");
        scanf("%d", &choose);

        switch(choose){
            case 1:{ //cadastro de alunos
                limpar_terminal();
                cadastro_alunos(&alunos, &idx_alu);
                break;
            };
            case 2:{ //cadastro de professores
                limpar_terminal();
                cadastro_professores(&professores, &idx_prof);
                break;
            };
            case 3:{ //cadastro de disciplinas
                limpar_terminal();
                cadastro_disciplinas(&disciplinas, &idx_disc);
                break;
            }
            case 4:{
                limpar_terminal();

                int choose_relat = 1;

                while(choose_relat){

                    printf("\nQual relatorio deseja visualizar?\n");
                    printf("1 - Alunos\n"
                           "2 - Professores\n"
                           "3 - Disciplinas\n"
                           "0 - Sair\n");
                    scanf("%d", &choose_relat);
                    
                    limpar_terminal();

                    if(choose_relat < 0 || choose_relat > 3){
                        printf("Valor indefinido!\n");
                        break;
                    }

                    relatorio(professores, idx_prof, alunos, idx_alu, disciplinas, idx_disc, choose_relat);
                }
                
                break;
            }
        }
    };
    
    return 0;
}