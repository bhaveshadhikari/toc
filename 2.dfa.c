// implementing dfa that accepts string with even number of zeros and even number of ones

/*
->((0))<-----0---->(1)
    ^               ^
    |               |
    |               |
    1               1
    |               |
    |               |
    v               v
   (2)<-----0----->(3)

transistion table:
  |  0   1
-----------
0 |  1   2  
1 |  0   3
2 |  3   0
3 |  2   1

*/

#include<stdio.h>
#include<string.h> 
int main(){
    int startState = 0;
    int finalState = 0;
    int transistionTable[][2]={
        {1,2},
        {0,3},
        {3,0},
        {2,1}
    };
    int currentState = startState;

    //start Automation
    char string[]="11000101";

    int length = strlen(string);
    printf("string to process: %s\n",string);

    for (int i = 0; i < length; i++)
    {
        //map character to integer
        int readBit = string[i] - '0';
        printf("d(q%d,%d) -> ",currentState,readBit);
        currentState = transistionTable[currentState][readBit];
        printf("q%d\n",currentState);
    }
    if (currentState == finalState)
        printf("accepted");
    else 
    printf("rejected");
    return 0;  

}

/*
string to process: 11000101
d(q0,1) -> q2
d(q2,1) -> q0
d(q0,0) -> q1
d(q1,0) -> q0
d(q0,0) -> q1
d(q1,1) -> q3
d(q3,0) -> q2
d(q2,1) -> q0
accepted
*/