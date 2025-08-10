#include <stdio.h>

typedef struct{
    int day, month, year;
} date;

typedef struct{
    char name[50];
    char cpf[12];
    char gender;
    date birthday;
} cadastre;

cadastre register_client(){

    cadastre client;

    printf("Name: ");
    scanf(" %[^\n]", client.name);
    printf("CPF: ");
    scanf(" %[^\n]", client.cpf);
    printf("Gender: ");
    scanf(" %c", &client.gender);
    printf("Birthday: ");
    scanf("%d %d %d", &client.birthday.day,
                      &client.birthday.month,
                      &client.birthday.year);

    return client;

}

int main(){

    cadastre client = register_client();

    printf("Name: %s\n"
           "CPF: %s\n"
           "Gender: %c\n"
           "Birthday: %d / %d / %d\n", client.name, client.cpf, client.gender, client.birthday.day, client.birthday.month, client.birthday.year);

    return 0;
}

