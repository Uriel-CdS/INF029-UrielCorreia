#include <stdio.h>

void read_carac(char carac[3])
{
    for(int i = 0; i < 3; i++){
        scanf(" %c", &carac[i]);
    }
}

int main(){

    char carac[3];

    read_carac(carac);

    for(int i = 0; i < 3; i++){
        printf("%c", carac[i]);
    }

    return 0;
}