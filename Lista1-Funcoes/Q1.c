#include <stdio.h>

int some(int n1, int n2)
{
    int som;
    return som = n1 + n2;
}

int main(){

    int soma, n1, n2;

    scanf("%d", &n1);
    scanf("%d", &n2);

    soma = some(n1, n2);

    printf("%d + %d = %d\n", n1, n2, soma);

    return 0;
}