#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

///Unos 10A3B1C
///Izlaz AAAAAAAAAABBBC

int isDigit(char ch){
    (ch >= '0' && ch <= '9')? 1:0;
}


int main()
{
    char ch;
    int broj = 0;

    int parFlag = -1;
    while((ch = getchar()) != '\n'){
        if(ch >= '0' && ch <= '9'){
            broj = broj * 10 + ch - '0';
            parFlag = 1;
        }
        if(ch >= 'A' && ch <= 'Z'){
            parFlag = 0;
        }
        if(parFlag == 0){
            for(int i = 0;i < broj; i++){
                putchar(ch);
            }
            broj = 0;
            parFlag = -1;
        }
    }

    return 0;
}
