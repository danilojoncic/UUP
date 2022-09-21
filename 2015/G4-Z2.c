#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

///Unos abcdefghijklmnopq
///Izlaz abCDefGHijKLmnOPq


int main()
{
    char ch;
    int counter = 0;

    while((ch = getchar()) != '\n'){
        if(ch >= 'a' && ch <= 'z'){
            counter++;
        }
        if((counter == 3) || (counter == 4)){
            ch -= 32;
            putchar(ch);
        }else{
            putchar(ch);
        }
        if(counter > 4){
            counter = 1;
        }
    }
    return 0;
}
