#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
    "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
    "while"
};

int is_keyword(const char *word) {

    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; //keyword
        }
    }
    return 0; //not keyword
}

int is_valid_identifier(const char *word) {
    // Check if the word is empty or starts with a digit
    if (strlen(word) == 0 || isdigit(word[0])) {
        return 0; // Not a valid identifier
    }

    for (int i = 0; i < strlen(word); i++) {
        // A valid identifier can contain letters, digits, or underscore,
        // but it cannot start with a digit.
        if (!isalnum(word[i]) && word[i] != '_') {
            return 0; 
        }
    }
    return 1;
}

int main() {
    char word[50];

    printf("Enter a word: ");
    scanf("%s", word);

    if (is_keyword(word)) {
        printf("%s is a keyword.\n", word);
    } else if (is_valid_identifier(word)) {
        printf("%s is an identifier.\n", word);
    } else {
        printf("None\n");
    }

    return 0;
}

/*

Enter a word: int
int is a keyword.

Enter a word: var1
var1 is an identifier
*/