#include <stdio.h>
#include <stdlib.h>

//Q1
int validate(char data[]){

    int datavalida = 1;
    int day, month, age; 
    int j = 0, i = 0;
    char capture[10];

    scanf(" %[^\n]", data);

    //capturando day
    while(data[i] != '/'){
    capture[j++] = data[i++];
    }
    capture[j] = '\0';
    day = atoi(capture);
    i++, j = 0;

    //capturando month
    while(data[i] != '/'){
    capture[j++] = data[i++];
    }
    capture[j] = '\0';
    month = atoi(capture);
    i++, j = 0;

    //capturando age
    while(data[i] != '\0'){
    capture[j++] = data[i++];
    }
    capture[j] = '\0';
    age = atoi(capture);
    i++, j = 0;

    if(age % 4 == 0){
        switch(month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:{
                if(day > 31 || day < 0){
                    datavalida = 0;
                }
                break;
            }
            case 4: case 6: case 9: case 11:{
                if(day > 30 || day < 0){
                    datavalida = 0;
                }
                break;
            }
            case 2:{
                if(day > 29 || day < 0){
                    datavalida = 0;
                }
                break;
            }
        }
    } else{
        switch (month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:{
                if(day > 31 || day < 0){
                    datavalida = 0;
                }
                break;
            } 
            case 4: case 6: case 9: case 11:{
                if(day > 30 || day < 0){
                    datavalida = 0;
                }
                break;
            }
            
            case 2:{
                if(day > 28 || day < 0){
                    datavalida = 0;
                }
                break;
            }
        } 
    }

    return datavalida;
}

//Q3
int searchcar(char string[], char carac_search){

    int idx_search = 0;

    scanf(" %[^\n]", string);
    scanf("%c", carac_search);

    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == carac_search){
            idx_search++;
        }
    }
    return idx_search;
}

//Q4
int searchwor(char string[], char word[]){

    int idx_search = 0;
    int i = 0, j = 0;

    scanf(" %[^\n]", string);
    scanf("%s", word);

    for(i = 0; string[i] != '\0'; i++){
        if(string[i] == word[j]){
            j++;
        } else{
            j = 0;
        }
        if(word[j] == '\0'){
            j = 0;
            idx_search++;
        }
    }
}