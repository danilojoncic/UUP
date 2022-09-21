#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

///Unos AbDfghjk
///Izlaz ADfj


///maltene radi da valja,samo treba rijesiti problem razlike velikih ili malih slova
int main()
{
    int counter = 1;
    char ch;
    char prev = 0;
    while((ch = getchar()) != '\n'){

        if(ch == prev+1 || ch == prev - 1 || ch == prev + 33 || ch == prev - 31){
            counter++;
            prev = ch;
            continue;
        }

        putchar(ch);



        printf(" Broj iteracije = %d, prev = %c, ch = %c\n",counter,prev,ch);
        counter++;
        prev = ch;
    }

    return 0;
}
