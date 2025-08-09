#include <stdio.h>

void read_vec(int vector[])
{
    for(int i = 0; i < 3; i++){
        scanf("%d", &vector[i]);
    }
}

int main(){

    int vector[3];

    read_vec(vector);

    for(int i = 0; i < 3; i++){
        printf("%d ", vector[i]);
    }

    return 0;
}