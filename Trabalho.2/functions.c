#include <stdio.h>
#include <stdlib.h>

#include "header.h"

#define TAM 10

void insertion(Structure structure[TAM]){
    
    int position;

    do{
        printf("Posicao: ");
        scanf("%d", &position);
    }while(position >= 10 || position < 0);

    if(structure[position].data == NULL){
        printf("Estrutura auxiiliar ainda não criada!\n");
        ins_straux(structure, position);
    }  

    if(!ins_verify(structure, position)) return;

    int valor;

    printf("Valor a inserir: ");
    scanf("%d", &valor);

    structure[position].data[structure[position].qtd] = valor;
    structure[position].qtd++;
    
}

void ins_straux(Structure structure[TAM], int position){

    int size;

    do{
        printf("Informe o tamanho total: ");
        scanf("%d", &size);
    }while(size < 0);

    structure[position].data = (int *) malloc(size * sizeof(int));
    if(structure[position].data == NULL){
        printf("Erro a alocar memória!\n");
        return;
    }

    structure[position].size = size;
    structure[position].qtd = 0;
}

int ins_verify(Structure structure[TAM], int position){
    
    if(structure[position].qtd >= structure[position].size){
        printf("Estrutura auxiliar cheia!\n");
        return 0;
    } return 1;
}