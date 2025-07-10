#include <stdio.h>
#include <stdlib.h>

#include "header.h"

#define TAM 10

void insertion(Structure structure[TAM]){
    
    int position;

    do{
        printf("\nPosicao da estrutura auxiliar: ");
        scanf("%d", &position);
    }while(position >= 10 || position < 0);

    if(structure[position].data == NULL){
        printf("\nEstrutura auxiliar ainda nao criada!\n");
        ins_straux(structure, position);
    }  

    if(!ins_verify(structure, position)) return;

    int valor;

    printf("\nValor a inserir: ");
    scanf("%d", &valor);

    structure[position].data[structure[position].qtd] = valor;
    structure[position].qtd++;

    bubble_sort(structure, position);
    
}

void ins_straux(Structure structure[TAM], int position){

    int size;

    do{
        printf("\nInforme o tamanho total: ");
        scanf("%d", &size);
    }while(size < 0);

    structure[position].data = (int *) malloc(size * sizeof(int));
    if(structure[position].data == NULL){
        printf("\nErro a alocar memória!\n");
        return;
    }

    structure[position].size = size;
    structure[position].qtd = 0;
}

int ins_verify(Structure structure[TAM], int position){
    
    if(structure[position].qtd >= structure[position].size){
        printf("\nEstrutura auxiliar cheia!\n");
        return 0;
    } return 1;
}

void bubble_sort(Structure structure[TAM], int position){

    int n = structure[position].qtd;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(structure[position].data[j] > structure[position].data[j + 1]){
                int temp = structure[position].data[j];
                structure[position].data[j] = structure[position].data[j + 1];
                structure[position].data[j + 1] = temp;
            }
        }
    }
}

void list_struct(Structure structure[TAM]){

    for(int i = 0; i < TAM; i++){
        if(structure[i].data == NULL){
            printf("\nPosição %d: Estrutura auxiliar não criada!\n", i);
        }
        else {

            int qtd = structure[i].qtd;
            int size = structure[i].size;

            printf("\nEstrutura auxiliar da posicao %d\n"
                   ">> Tamanho da estrutura auxiliar: %d\n"
                   ">> Quantidade de elementos na estrutura aux. : %d\n"
                   ">> Elementos da estrutura aux. : ", i, size, qtd);

            for(int j = 0; j < qtd; j++){
                printf("%d", structure[i].data[j]);
                if(j < qtd - 1){
                    printf(", ");
                }
            }
            printf("\n");
        }
    }
}

int* gather_allstruct(Structure structure[TAM], int *total){

    int some = 0;

    for(int i = 0; i < TAM; i++){
        if(structure[i].data != NULL){
            some += structure[i].qtd;
        }
    }

    *total = some;

    int *ptr = (int*) malloc (some * sizeof(int));

    int idx = 0;

    for(int i = 0; i < TAM; i++){
        if(structure[i].data != NULL){
            for(int j = 0; j < structure[i].qtd; j++){
                ptr[idx] = structure[i].data[j];
                idx++;
            }
        }
    }

    bbs_allstruct(ptr, some);

    return ptr;
}

void list_allstruct(Structure structure[TAM]){

    int total;
    int *ptr = gather_allstruct(structure, &total);

    if(ptr == NULL || total == 0){
        printf("\nNenhum elemento inserido nas estruturas!\n");
        return;
    }

    printf("\nTodos os elementos: ");

    for(int i = 0; i < total; i++){
        printf("%d", ptr[i]);
        if(i < total - 1){
            printf(", ");
        }
    }
    printf("\n");

    free(ptr);
}

void bbs_allstruct(int *vector, int some){

    for(int i = 0; i < some - 1; i++){
        for(int j = 0; j < some - 1 - i; j++){
            if(vector[j] > vector[j + 1]){
                int temp = vector[i + 1];
                vector[i + 1] = vector[i];
                vector[i] = temp;
            }
        }
    }
}

void exclusion(Structure structure[TAM]){

    int position;

    do{
        printf("\nInforme a posicao da estrutura auxiliar: ");
        scanf("%d", &position);
    } while (position < 0 || position > 9);

    int verify = 0;
    
    if(!ex_verify(structure, position)) return;

    int valor;

    printf("\nInforme o valor que deseja: ");
    scanf("%d", &valor);

    int find = 0;

    for(int i = 0; i < structure[position].qtd; i++){
        if(structure[position].data[i] == valor){
            find = 1;

            for(int j = 0; j < structure[position].qtd - 1; j++){
                structure[position].data[j] = structure[position].data[j + 1];
            }

            structure[position].qtd--;

            printf("\nValor %d excluído!\n", valor);
            break;
        } 
    }

    if(!find){
        printf("\nValor não encontrado!\n");
    }
}

int ex_verify(Structure structure[TAM], int position){
    if(structure[position].data == NULL || structure[position].qtd == 0){
        printf("\nEstrutura auxiliar vazia/inexistente!\n");
        return 0;
    } return 1;
}

void re_alloc(Structure structure[TAM]){

    int position;

    do{
        printf("\nInforme a posicao da estrutura auxiliar: ");
        scanf("%d", &position); 
    } while(position < 0 || position > 9);

    if(structure[position].data == NULL){
        printf("\nEstrutura auxiliar vazia/inexistente\n");
        return; 
    }

    int additional;

    do{
        printf("\nInforme o numero de posicoes a adicionar: ");
        scanf("%d", &additional);
    } while(additional < 0);

    int new_size = structure[position].size + additional; 

    int *new = realloc(structure[position].data, new_size * sizeof(int));
    if(new == NULL){
        printf("\nErro ao realocar memória!\n");
        return;
    }

    structure[position].data = new;
    structure[position].size = new_size;

}

void menu(Structure structure[TAM]){

    int choose;

    do{
        printf("\n1 - Inserir valor;\n"
                 "2 - Inserir estrutura auxiliar;\n"
                 "3 - Listar estruturas auxiliares;\n"
                 "4 - Listar todas os elementos;\n"
                 "5 - Excluir valor;\n"
                 "6 - Aumentar tamanho da estrutura auxiliar;\n"
                 "0 - Sair;\n");
        printf("\nInforme o que deseja fazer: ");
        scanf("%d", &choose);
        
        switch(choose){
            case 1:
                insertion(structure);
                break;
            case 2:{
                int position;

                printf("\nInforme a posicao da estrutura auxiliar (0 - 9):");
                scanf("%d", &position);
                ins_straux(structure, position);
                break;

            }case 3:
                list_struct(structure);
                break;
            case 4:
                list_allstruct(structure);
                break;
            case 5:
                exclusion(structure);
                break;
            case 6:
                re_alloc(structure);
                break;
            case 0:
                printf("\nFechando programa...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(choose != 0);
}