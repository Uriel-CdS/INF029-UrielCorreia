#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h"

#define TAM 10

typedef struct {
    int *dados;
    int tamanho;
    int qtd;
} Estrutura;

Estrutura estruturas[TAM];

void inicializar() {
    for (int i = 0; i < TAM; i++) {
        estruturas[i].dados = NULL;
        estruturas[i].tamanho = 0;
        estruturas[i].qtd = 0;
    }
}

void finalizar() {
    for (int i = 0; i < TAM; i++) {
        if (estruturas[i].dados != NULL)
            free(estruturas[i].dados);
        estruturas[i].dados = NULL;
    }
}

int criarEstruturaAuxiliar(int posicao, int tamanho) {
    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;
    if (tamanho < 1)
        return TAMANHO_INVALIDO;

    posicao--;

    if (estruturas[posicao].dados != NULL)
        return JA_TEM_ESTRUTURA_AUXILIAR;

    estruturas[posicao].dados = (int*) malloc(tamanho * sizeof(int));
    if (estruturas[posicao].dados == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    estruturas[posicao].tamanho = tamanho;
    estruturas[posicao].qtd = 0;

    return SUCESSO;
}

int inserirNumeroEmEstrutura(int posicao, int valor) {
    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    posicao--;

    if (estruturas[posicao].dados == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (estruturas[posicao].qtd >= estruturas[posicao].tamanho)
        return SEM_ESPACO;

    estruturas[posicao].dados[estruturas[posicao].qtd++] = valor;

    return SUCESSO;
}

int excluirNumeroDoFinaldaEstrutura(int posicao) {
    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    posicao--;

    if (estruturas[posicao].dados == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (estruturas[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    estruturas[posicao].qtd--;

    return SUCESSO;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    posicao--;

    if (estruturas[posicao].dados == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (estruturas[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int i, j;
    for (i = 0; i < estruturas[posicao].qtd; i++) {
        if (estruturas[posicao].dados[i] == valor) {
            for (j = i; j < estruturas[posicao].qtd - 1; j++) {
                estruturas[posicao].dados[j] = estruturas[posicao].dados[j + 1];
            }
            estruturas[posicao].qtd--;
            return SUCESSO;
        }
    }

    return NUMERO_INEXISTENTE;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    posicao--;

    if (estruturas[posicao].dados == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    for (int i = 0; i < estruturas[posicao].qtd; i++)
        vetorAux[i] = estruturas[posicao].dados[i];

    return SUCESSO;
}

void ordenar(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int tmp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = tmp;
            }
        }
    }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
    if (retorno != SUCESSO)
        return retorno;

    int idx = posicao - 1;
    ordenar(vetorAux, estruturas[idx].qtd);

    return SUCESSO;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int total = 0;

    for (int i = 0; i < TAM; i++) {
        if (estruturas[i].dados != NULL) {
            for (int j = 0; j < estruturas[i].qtd; j++) {
                vetorAux[total++] = estruturas[i].dados[j];
            }
        }
    }

    return total == 0 ? TODAS_ESTRUTURAS_AUXILIARES_VAZIAS : SUCESSO;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    if (retorno != SUCESSO)
        return retorno;

    int total = 0;
    for (int i = 0; i < TAM; i++) {
        if (estruturas[i].dados != NULL)
            total += estruturas[i].qtd;
    }

    ordenar(vetorAux, total);
    return SUCESSO;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    posicao--;

    if (estruturas[posicao].dados == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (estruturas[posicao].tamanho + novoTamanho < 1)
        return NOVO_TAMANHO_INVALIDO;

    int *novo = (int*) realloc(estruturas[posicao].dados, (estruturas[posicao].tamanho + novoTamanho) * sizeof(int));
    if (novo == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    estruturas[posicao].dados = novo;
    estruturas[posicao].tamanho += novoTamanho;
    if (estruturas[posicao].qtd > estruturas[posicao].tamanho)
        estruturas[posicao].qtd = estruturas[posicao].tamanho;

    return SUCESSO;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    posicao--;

    if (estruturas[posicao].dados == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (estruturas[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return estruturas[posicao].qtd;
}

No* montarListaEncadeadaComCabecote() {
    No *cabeca = (No*) malloc(sizeof(No));
    if (!cabeca) return NULL;
    cabeca->prox = NULL;
    No *atual = cabeca;

    for (int i = 0; i < TAM; i++) {
        if (estruturas[i].dados != NULL) {
            for (int j = 0; j < estruturas[i].qtd; j++) {
                No *novo = (No*) malloc(sizeof(No));
                if (!novo) continue;
                novo->conteudo = estruturas[i].dados[j];
                novo->prox = NULL;
                atual->prox = novo;
                atual = novo;
            }
        }
    }

    if (cabeca->prox == NULL) {
        free(cabeca);
        return NULL;
    }

    return cabeca;
}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
    No *atual = inicio->prox;
    int i = 0;
    while (atual != NULL) {
        vetorAux[i++] = atual->conteudo;
        atual = atual->prox;
    }
}

void destruirListaEncadeadaComCabecote(No **inicio) {
    No *atual = *inicio;
    while (atual != NULL) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}

void dobrar(int *x) {
    *x *= 2;
}
