// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Uriel Correia dos Santos  
//  email: 20242160006@ifba.edu.br
//  Matrícula: 202460006@ifba.edu.br
//  Semestre: 2025.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include "UrielSantos20242160006.h"

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a){
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

//>>>>>>Q1 finalizada
int q1(char data[]){
   
   int datavalida = 1;
   int day, month, age; 
   int j = 0, i = 0;
   char capture[10];

   //capturando day
   while(data[i] != '/'){
      capture[j++] = data[i++];
   }
   capture[j] = '\0';
   day = atoi(capture);
   i++, j = 0;

   //capturando month
   while(data[i] != '/'){
      capture[j++] = data[i++];
   }
   capture[j] = '\0';
   month = atoi(capture);
   i++, j = 0;

   //capturando age
   while(data[i] != '\0'){
      capture[j++] = data[i++];
   }
   capture[j] = '\0';
   age = atoi(capture);
   i++, j = 0;

   if(age % 4 == 0){
      switch(month){
         case 1: case 3: case 5: case 7: case 8: case 10: case 12:{
               if(day > 31 || day < 0){
                  datavalida = 0;
               }
               break;
         }
         case 4: case 6: case 9: case 11:{
               if(day > 30 || day < 0){
                  datavalida = 0;
               }
               break;
         }
         case 2:{
               if(day > 29 || day < 0){
                  datavalida = 0;
               }
               break;
         }
      }
   } else{
      switch (month){
         case 1: case 3: case 5: case 7: case 8: case 10: case 12:{
               if(day > 31 || day < 0){
                  datavalida = 0;
               }
               break;
         } 
         case 4: case 6: case 9: case 11:{
               if(day > 30 || day < 0){
                  datavalida = 0;
               }
               break;
         }
         
         case 2:{
               if(day > 28 || day < 0){
                  datavalida = 0;
               }
               break;
         }
      } 
   }

   if(datavalida)
      return 1;
   else
      return 0;
}

// Funções para a Q2\/\/\/\/\/
typedef struct{
    int dias;
    int mes;
    int ano;
    int retorno;
} DiasMesesAnos;

//validando se é um ano bissexto
int validye(int ano){
   return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

//passando para a variável mês qual a quantidade de dias
int daysmonth(int mes, int ano){
   int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   if (mes == 2 && validye(ano)){
      return 29;
   } return dias[mes - 1];
}

//separando a string em partes dia, mes, ano
void extrair(char data[], int *dia, int *mes, int *ano){

   char aux[5];
   int i = 0, j = 0;

   // Dia
   while (data[i] != '/') aux[j++] = data[i++];
   aux[j] = '\0';
   *dia = atoi(aux);

   // Mês
   i++, j = 0;
   while (data[i] != '/') aux[j++] = data[i++];
   aux[j] = '\0';
   *mes = atoi(aux);

   // Ano
   i++, j = 0;
   while (data[i] != '\0') aux[j++] = data[i++];
   aux[j] = '\0';
   *ano = atoi(aux);
}

int totalDias(int d, int m, int a) {

   int total = d;

   //calculo dos dias no ano atual
   for (int i = 1; i < m; i++) {
      total += daysmonth(i, a);
   }

   //calculo dos dias totais até o início do ano atual
   total += (a - 1) * 365;
   total += (a - 1) / 4 - (a - 1) / 100 + (a - 1) / 400;

   return total;
}

//>>>>>>Q2 finalizada
DiasMesesAnos q2(char datainicial[], char datafinal[]) {
   
   DiasMesesAnos dma;

   if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
   } else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
   }

   int dia1, mes1, ano1;
   int dia2, mes2, ano2;

   extrair(datainicial, &dia1, &mes1, &ano1);
   extrair(datafinal, &dia2, &mes2, &ano2);

   int total1 = totalDias(dia1, mes1, ano1);
   int total2 = totalDias(dia2, mes2, ano2);

   if (total2 < total1) {
      dma.retorno = 4;
      return dma;
   }

   int difDias = total2 - total1;

   dma.ano = difDias / 365;
   difDias %= 365;
   dma.mes = difDias / 30;
   dma.dias = difDias % 30;

   dma.retorno = 1;
   return dma;
}

//>>>>>Q3 finalizada
int q3(char *texto, char c, int isCaseSensitive){

   int qtdOcorrencias = 0;

   if(isCaseSensitive == 1){ //considerando diferença entre maiúscula e minúscula
      for(int i = 0; texto[i] != '\0'; i++){
         if(texto[i] == c){
            qtdOcorrencias++;
         }
      }
   } else if(!isCaseSensitive){ //desconsiderando diferença entre maiúscula e minúscula
      for(int i = 0; texto[i] != '\0'; i++){
        if((c >= 'A' && c <= 'Z' && (texto[i] == c || texto[i] == c + 32)) ||
           (c >= 'a' && c <= 'z' && (texto[i] == c || texto[i] == c - 32)))
            qtdOcorrencias++;
      }
   }
 
   return qtdOcorrencias;
}

//>>>>>Q4 finalizada
int q4(char *strTexto, char *strBusca, int posicoes[30]){

   int qtdOcorrencias = 0;
   int i = 0, j = 0;

   for (i = 0; strTexto[i] != '\0'; i++) {
      for (j = 0; strBusca[j] != '\0' && strTexto[i + j] == strBusca[j]; j++);
      
      if (strBusca[j] == '\0') {
         posicoes[qtdOcorrencias++] = i;
         posicoes[qtdOcorrencias++] = i + j - 1;
      }
   }

   return qtdOcorrencias / 2;
}

//>>>>>Q5 finalizada
int q5(int num){

    char num_ch[100], interm[100];
    int idx = 0, i;

    sprintf(num_ch, "%d", num);

    while(num_ch[idx] != '\0'){
        idx++;
    };

    int idx_2 = idx - 1;

    for(i = 0; i < idx ; i++){
        interm[i] = num_ch[idx_2--];
    }

    interm[idx] = '\0';

    num = atoi(interm);

    return num;
}

//>>>>>Q6 finalizada
int q6(int numerobase, int numerobusca){

    int qtdOcorrencias = 0;
    char str[100];
    char str_nbusca[100];
    int i, j;

    sprintf(str, "%d", numerobase);
    sprintf(str_nbusca, "%d", numerobusca);

    for(i = 0; str[i] != '\0'; i++){
        for(j = 0; str_nbusca[j] != '\0' && str[i + j] == str_nbusca[j]; j++);
        if(str_nbusca[j] == '\0'){
            qtdOcorrencias++;
        }
    }
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */
 int q7(char matriz[8][10], char palavra[5])
 {
   int achou;
   return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}