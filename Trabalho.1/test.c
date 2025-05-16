#include <stdio.h>
#include <stdlib.h>

int q6(int numerobase, int numerobusca)
{
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

int q5(int num)
{   
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

int main(){

    int num = 0;

    printf("Informe o número: ");
    scanf("%d", &num);

    int num_inv = q5(num);

    printf("\nNúmero invertido: %d", num_inv);

    return 0;

}