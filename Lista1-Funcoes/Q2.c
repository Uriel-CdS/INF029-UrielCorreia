#include <stdio.h>

int subtracion(int n1, int n2, int n3)
{
    int sub;
    return sub = n1 - n2 - n3;
}

int main()
{
    int sub, n1, n2, n3;

    scanf("%d %d %d", &n1, &n2, &n3);

    sub = n1 - n2 - n3;

    printf("%d - %d - %d = %d", n1, n2, n3, sub);

    return 0;
}