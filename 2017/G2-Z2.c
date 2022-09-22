#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

///Unos: ab11cnh23zk37j1jht21m
///Izlaz: 49





int main()
{
    ///ab11cnh23zk37j1jht21m
    char ch;
    char prevAlf;
    int broj = 0;
    int res = 0;
    int numFlag = 0;
    prevAlf = getchar();
    while((ch = getchar()) != '\n'){
        printf("broj : %d ,   res : %d , numFlag : %d, prev:  %c, ch :  %c \n",broj,res,numFlag,prevAlf,ch);
        if(ch >= 'a' && ch <= 'z'){
            if(abs(prevAlf - ch) <= 2){
                res+= broj;
            }
            numFlag = 0;
            prevAlf = ch;
        }
        if(ch >= '0' && ch <= '9'){
            numFlag = 1;
        }
        if(numFlag){
            broj = broj * 10 + ch - '0';
        }else{
            broj = 0;
        }



    }
    printf("%d",res);




    return 0;
}
