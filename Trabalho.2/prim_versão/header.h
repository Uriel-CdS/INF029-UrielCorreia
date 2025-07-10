#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>

#define TAM 10

typedef struct{
    int *data; //dados
    int qtd;   //qtd de dados inseridos em cada espaço
    int size;  //qtd total de dados em cada espaço
}Structure;

// Inserindo
void insertion(Structure structure[TAM]); //inserindo valor na estrutura auxiliar
void ins_straux(Structure structure[TAM], int position); //criando uma estrutura auxiliar
int ins_verify(Structure structure[TAM], int position); //verifica se a estrutura auxilair está cheia

// Ordenação
void bubble_sort(Structure structure[TAM], int position); //ordenando os valores das estruturas auxiliares
void bbs_allstruct(int *vector, int some); //ordenando todos os elementos

// Listagem
void list_struct(Structure structure[TAM]); //listando todas as estruturas auxiliares
int* gather_allstruct(Structure structure[TAM], int *total); //juntando todos os elementos de todas as estr. aux. juntas
void list_allstruct(Structure structure[TAM]); //listando todos os elementos

// Exclusão
void exclusion(Structure structure[TAM]); //excluindo valor da estrutura auxiliar
int ex_verify(Structure structure[TAM], int position); //verifica se a estrutura auxiliar está vazia ou inexistente

// Realloc
void re_alloc(Structure structure[TAM]); //aumentando a memória de uma estrutura auxiliar

// Menu
void menu(Structure structure[TAM]); //menu de interação

#endif