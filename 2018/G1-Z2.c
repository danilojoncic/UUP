#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


///unos ab123de5000f4g567hh
///izlaz 690

int main() {

    int res = 0;
    int broj = 0;
    char ch;
    int trocifren = 0;

    while((ch = getchar()) != '\n'){
        if(ch >= 'a' && ch <= 'z'){
            if(broj >= 100 && broj <= 999){
                trocifren += broj;
            }

            broj = 0;
            continue;
        }
        if(ch >= '0' && ch <= '9'){
            broj = broj * 10 + ch - '0';
        }
        printf("  broj : %d\n",broj);
    }
    printf("%d",trocifren);




    return 0;
}
