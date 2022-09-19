#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>



int myToUpper(int c){
    int razlika = 'a' - 'A';
    if(c >= 'a' && c <= 'z'){
        return c - razlika;
    }
    return c;
}

    ///AAABABBBBCC
    ///A3B1A1B4C2

int main() {
    ///GETCHAR i PUTCHAR i ULAZNA SEKVENCA
    char trenutni;
    char prethodni;
    int i = 1;

    prethodni = getchar();
    prethodni = myToUpper(prethodni);

    while((trenutni = getchar()) != '\n'){
        trenutni = myToUpper(trenutni);
        if(trenutni == prethodni){
            i++;
        }else{
            putchar(prethodni);
            printf("%d",i);
            i = 1;
            prethodni = trenutni;
        }
    }

    putchar(prethodni);
    printf("%d",i);


    return 0;
}
