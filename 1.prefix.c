#include<stdio.h>
#include<string.h>
char string[]="COMPUTATION";
void findPrefix(){
    for (int i = 0; i < strlen(string)-1; i++)
    {
        for (int j = 0; j <= i; j++){
            printf("%c",string[j]);
        }
        printf("\n");
    } 
}

void findSuffix(){
    for (int i = 0; i < strlen(string)-1; i++)
    {
        for (int j = i+1; j < strlen(string); j++){
            printf("%c",string[j]);
        }
        printf("\n");
    }  
}

void findSubstring(int x, int y){
    for (int i = x; i <= y; i++){
        printf("%c",string[i]);
    }
}

int main(){
    printf("suffixes: \n");
    findPrefix();
    printf("prefixes: \n");
    findSuffix();
    printf("substring (2,6): \n");
    findSubstring(2,6);
    return 0;
}

/*
suffixes: 
C
CO
COM
COMP
COMPU
COMPUT
COMPUTA
COMPUTAT
COMPUTATI
COMPUTATIO
prefixes: 
OMPUTATION
MPUTATION
PUTATION
UTATION
TATION
ATION
TION
ION
ON
N
substring (2,6):
MPUTA
*/