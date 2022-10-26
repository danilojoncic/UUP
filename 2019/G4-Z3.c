#include <stdio.h>
#include <stdlib.h>


/**
UUP-2019-2020-KLK1-G4-Z3
3. (7p) Nacrtati sledeću figuru za uneto n (n > 2):
n = 5   n=6      n=9
aACDe   aACDEf   aACDEFGHi
AbCdE   AbCDeF   AbCDEFGhI
ABcCE   ABccEF   ABcCEFgHI
AbCdE   ABcdEF   ABCdEfGHI
aBCDe   AbCDeE   ABCDeEGHI
        aBCDEf   ABCdEfGHI
                 ABcDEFgGI
                 AbCDEFGhI
                 aBCDEFGHi
*/




int main()
{
    int n;
    char slovo = 'A';
    char slovo2 = slovo;
    scanf("%d",&n);
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= n; j++){

            if (i != j && i+j != n+1) {
                if (j == i+1 && i%2)
                    printf("%c", 'A' + j-2);
                else
                    printf("%c", 'A' + j-1);

            }else{
                if(j==i+1 && i % 2)
                    printf("%c",'a'+j-2);
                else
                    printf("%c",'a'+j-1);
            }
        }
        printf("\n");
        slovo = 'A';
    }






    return 0;
}
