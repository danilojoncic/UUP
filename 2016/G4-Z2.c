#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

///Unos: aaababbBBC
///Izlaz: a3b1a1b4c1


char low(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }else if(ch >= 'A' && ch <= 'Z'){
        ch+= 'a' - 'A';
    }
    return ch;
}


int main()
{
    char ch;
    char prev = 0;
    int counter = 1;

    prev = getchar();
    while((ch = getchar()) != '\n'){
        //printf("prev : %c, ch : %c \n",prev,ch);

        if(low(prev) == low(ch)){
            counter++;
            prev = low(ch);
        }
        if(low(prev) != low(ch)){
            putchar(prev);
            printf("%d",counter);
            prev = low(ch);
            counter = 1;
        }
    }

    putchar(prev);
    printf("%d",counter);



    return 0;
}
