#include <stdio.h>
#include "header.h"

#define TAM 10

int main(){

    Structure structure[TAM];

    for(int i = 0; i < TAM; i++){
        structure[i].data = NULL;
        structure[i].qtd = 0;
        structure[i].size = 0;
    }

    insertion(structure);

    return 0;
}