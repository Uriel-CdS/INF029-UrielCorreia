#include <stdio.h>

int is_greater(int n1, int n2){
    (n1 > n2) ? 1 : 0;
}

void create_str(int n1, int n2, char *str, int *i){

    if(n1 == 0 && n2 == 0){
        str[*i] = '\0';
        return;
    }

    int temp1 = n1 % 10;
    int temp2 = n2 % 10;

    if(is_greater(temp1, temp2)){
        str[(*i)++] = temp1 + '0';
        str[(*i)++] = temp2 + '0';
    } else{
        str[(*i)++] = temp2 + '0';
        str[(*i)++] = temp1 + '0';
    }

    n1 /= 10;
    n2 /= 10;

    create_str(n1 / 10, n2 / 10, str, i);
}

int main(){

    int n1 = 1250;
    int n2 = 2543;
    char str[20];
    int i = 0;

    create_str(n1, n2, str, &i);

    printf("%s", str);

    return 0;
}