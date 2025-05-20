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

int q1(char data[]) {
    int dia, mes, ano;
    extrair(data, &dia, &mes, &ano);

    if (ano < 1 || mes < 1 || mes > 12) return 0;

    int diasMes = daysmonth(mes, ano);
    if (dia < 1 || dia > diasMes) return 0;

    return 1;
}

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

int main(){
    char d_i[11];
    char d_f[11];

    printf("Informe a data inicial: ");
    scanf(" %[^\n]", d_i);

    printf("Informe a data final: ");
    scanf(" %[^\n]", d_f);

    DiasMesesAnos resultado = q2(d_i, d_f);

    if (resultado.retorno == 1) {
        printf("Diferença: %d ano(s), %d mes(es), %d dia(s)\n", resultado.ano, resultado.mes, resultado.dias);
    } else if (resultado.retorno == 2) {
        printf("Data inicial inválida.\n");
    } else if (resultado.retorno == 3) {
        printf("Data final inválida.\n");
    } else if (resultado.retorno == 4) {
        printf("Data final é anterior à data inicial.\n");
    }

    return 0;
}