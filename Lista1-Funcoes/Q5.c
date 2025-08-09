#include <stdio.h>

typedef struct
{
    int n[4];
} Fournumb;

Fournumb read_struct(){

    Fournumb nums;

    for(int i = 0; i < 4; i++){
        scanf("%d", &nums.n[i]);
    }

    return nums;
}

int main(){

    Fournumb nums = read_struct();

    for(int i = 0; i < 4; i++){
        printf("%d ", nums.n[i]);
    }

    return 0;
}