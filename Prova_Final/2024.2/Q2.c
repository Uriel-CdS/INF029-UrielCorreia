#include <stdio.h>

void reverse(int *vector, int start, int end){
    if(start >= end) return;
    int temp = vector[start];
    vector[start] = vector[end];
    vector[end] = temp;
    reverse(vector, start + 1, end - 1);
}

int main(){

    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(vector)  / sizeof(vector[0]);

    reverse(vector, 0, size - 1);

    for(int i = 0; i < size; i++){
        printf("%d ", vector[i]);
    }

    return 0;
}