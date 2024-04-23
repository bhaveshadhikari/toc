#include <stdio.h>
#include <string.h>

int top;

char s[10];

void push(int x){
    s[top++] = x;
}

void pop(){
    top--;
}

int main(){
    int i, n, state = 0;
    char a[10];
    printf("Program For PDA Which Accpets Strings Of (a^n)(b^n)\n");
    printf("Enter String:");
    scanf("%s",a);
    n = strlen(a);
    top = -1;
    
    for (i = 0; i < n; i++){
        if (a[i] == 'a' && state == 0){
            push(a[i]);
            state = 0;
        }
        else if (a[i] == 'b' && state == 0){
            pop(a[i]);
            state = 1;
        }
        else if (a[i] == 'b' && state == 1){
            pop();
            state = 1;
        }
        else
            break;
    }


    if (a[i] == '\0' && top == -1 && state == 1)
        printf("string accepted");
    else
        printf("String Rejected.");

    return 0;

}
/*
Program For PDA Which Accpets Strings Of (a^n)(b^n)
Enter String:aaaabbbb
string accepted
*/