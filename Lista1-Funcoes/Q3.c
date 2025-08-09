#include <stdio.h>

int fatorial(int n)
{
    if(n <= 0) return 0;
    else{
        int fat = n;
        for(int i = n - 1; i > 0; i--){
            fat *= i;
        }
        return fat;
    }
}

int main()
{
    int fat, n;

    scanf("%d", &n);

    fat = fatorial(n);

    printf("%d", fat);

    return 0;
}