#include <stdio.h>

typedef struct {
    char word[3][20]; 
} Words;

Words read_word() {
    Words w;

    for (int i = 0; i < 3; i++) {
        printf("Digite a %dª palavra: ", i + 1);
        scanf(" %s[^\n]", w.word[i]); 
    }

    return w;
}

int main() {
    Words word = read_word();

    printf("\nPalavras digitadas:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", word.word[i]);
    }

    return 0;
}
