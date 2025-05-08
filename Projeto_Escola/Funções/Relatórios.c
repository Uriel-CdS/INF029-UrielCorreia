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

void relatorio(Professor *prof, int idx_prof, Aluno *al, int idx_al, Disciplina *disc, int idx_disc, int choose_relatorio){
    switch(choose_relatorio){
        case 1:{ // relatório alunos

            printf("\nRelatorio de cadastro dos alunos\n");

            if(idx_al == 0){
                printf("Não há cadastro de alunos!\n");
            } else{
                for(int i = 0;i < idx_al; i++){

                    printf("Cadastro n%d\n", i + 1);
    
                    printf(">> Nome: %s\n", al[i].nome);
                    printf(">> CPF: %s\n", al[i].cpf);
                    printf(">> Matricula: %s\n", al[i].matricula);
                    printf(">> Sexo: %c\n", al[i].sexo);
                    printf(">> Data de aniversario: %02d/%02d/%02d\n", al[i].aniversario.dia,
                                                                 al[i].aniversario.mes,
                                                                 al[i].aniversario.ano);
                }
            }
     
            break;
        }
        case 2:{ // relatório professores

            printf("\nRelatorio de cadastro de professores\n");

            if(idx_prof == 0){
                printf("Não há cadastro de professores!\n");
            } else{
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
            }

            break;
        }
        case 3:{ // relatório disciplinas

            printf("\nRelatorio de cadastro de disciplinas\n");

            if(idx_disc == 0){
                printf("Nao ha cadastro de disciplinas!\n");
            } else{
                for(int i = 0; i < idx_disc; i++){

                    printf("Cadastro n%d\n", i + 1);

                    printf(">> Nome: %s\n", disc[i].nome);
                    printf(">> Semestre: %d\n", disc[i].semestre);
                    printf(">> Professor: %s\n", disc[i].professor);
                    printf(">> Codigo: %s\n", disc[i].codigo);
                }
            }
            
            break;
        }
        default:{
            printf("Valor indefinido!");
            break;
        }
    }
}