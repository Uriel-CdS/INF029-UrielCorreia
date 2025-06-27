#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>

#define TAM 10

typedef struct{
    int *data; //dados
    int qtd;   //qtd de dados inseridos em cada espaço
    int size;  //qtd total de dados em cada espaço
}Structure;

void insertion(Structure structure[TAM]); //inserindo valor na estrutura auxiliar

void ins_straux(Structure structure[TAM], int position); //criando uma estrutura auxiliar

int ins_verify(Structure structure[TAM], int position); //verifica se a estrutura auxilair está cheia

void bubble_sort(Structure structure[TAM], int position); //ordenando os valores das estruturas auxiliares

void list_struct(Structure structure[TAM]); //listando todas as estruturas auxiliares

void* gather_allstruct(Structure structure[TAM], int *ptr); //juntando todos os elementos de todas as estr. aux. juntas

void lis_allstruct(Structure structure[TAM]); //listando todos os elementos

#endif 