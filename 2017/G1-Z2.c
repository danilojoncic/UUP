#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

///Test primjer:
/// ab23Bnh46zu37uj1jht21m



int myIsDigit(int c){
    return ((c >= '0') && (c <= '9')) ? 1 : 0;
}

int myToUpper(int c){
    int razlika = 'a' - 'A';
    if(c >= 'a' && c <= 'z'){
        return c - razlika;
    }
    return c;
}



int main() {
    char ch;
    char prev = '\n';
    int broj = 0;
    int rezultat = 0;

    while((ch = getchar()) != '\n'){
        if(myIsDigit(ch)){
            broj*= 10;
            broj += ch - '0';
        }else{
            ch = myToUpper(ch);
            if(ch == prev){
                rezultat += broj;
            }
            broj = 0;
            prev = ch;
        }
    }
    printf("Zbir je : %d\n", rezultat);
    return 0;
}
