#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

///Unos ABC3DF5HFD6GFD7
///Izlaz 567
///ispisati trocifreni broj koji se sastoji od 3 poslednje cifre u ulaznom tekstu

int main()
{
    char ch;
    int broj = 0;
    int counter = 0;

    while((ch = getchar()) != '\n'){
        if(ch >= '0' && ch <= '9'){
            broj = broj * 10 + ch - '0';
            counter++;
        }
    }
    if(counter <= 3){
        printf("broj : %d",broj);
    }else if(counter > 3){
        broj %= 1000;
        printf("broj : %d",broj);
    }

    return 0;
}
