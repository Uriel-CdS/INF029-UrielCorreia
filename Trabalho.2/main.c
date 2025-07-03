#include <stdio.h>
#include "header.h"

int main(){

    Structure structure[TAM];

    for(int i = 0; i < TAM; i++){
        structure[i].data = NULL;
        structure[i].qtd = 0;
        structure[i].size = 0;
    }

    menu(structure);

    for (int i = 0; i < TAM; i++) {
        if (structure[i].data != NULL) {
            free(structure[i].data);
        }
    }

    return 0;
}