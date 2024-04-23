#include <stdio.h>
#include <string.h>

int states[] = {0, 1, 2, 3, 4, -1};
char string[] = "0011";

int main() {
    int currentState = states[0];
    int len = strlen(string);
    int i = 0;
    while (currentState != -1) {
        printf("Tape: %s, current state: %d\n", string, currentState);
        switch (states[currentState]) {
            case 0:
                if (string[i] == '0') {
                    string[i] = 'x';
                    currentState = 1;
                    i++;
                } else if (string[i] == 'y') {
                    currentState = 3;
                    i++;
                } else
                    currentState = -1;
                break;

            case 1:
                if (string[i] == '0') {
                    currentState = 1;
                    i++;
                } else if (string[i] == 'y') {
                    currentState = 1;
                    i++;
                } else if (string[i] == '1') {
                    currentState = 2;
                    string[i] = 'y';
                    i--;
                } else
                    currentState = -1;
                break;

            case 2:
                if (string[i] == '0') {
                    currentState = 2;
                    i--;
                } else if (string[i] == 'y') {
                    currentState = 2;
                    i--;
                } else if (string[i] == 'x') {
                    currentState = 0;
                    i++;
                } else
                    currentState = -1;
                break;

            case 3:
                if (string[i] == 'y') {
                    currentState = 3;
                    i++;
                } else if (string[i] == '\0') {
                    currentState = 4;
                    printf("accepted");
                    return 0;
                } else
                    currentState = -1;
                break;
        }
    }

    printf("rejected;");
    return 0;
}

/*
Tape: 0011, current state: 0
Tape: x011, current state: 1
Tape: x011, current state: 1
Tape: x0y1, current state: 2
Tape: x0y1, current state: 2
Tape: x0y1, current state: 0
Tape: xxy1, current state: 1
Tape: xxy1, current state: 1
Tape: xxyy, current state: 2
Tape: xxyy, current state: 2
Tape: xxyy, current state: 0
Tape: xxyy, current state: 3
Tape: xxyy, current state: 3
accepted
*/