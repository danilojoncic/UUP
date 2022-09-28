#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{
    int n;
    scanf("%d",&n);
///Ispis stabla
    for(int i = 0; i < n / 2; i++){
        for(int j = 0; j < n / 2 * 2 + 1;j++){
            if(j < n - 1){
                printf(" ");
                continue;
            }
            printf("|");
        }
        printf("\n");
    }
///Ispis krosnje
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 2 - (n % 2) - i ;j++){   ///N.J.R. pristup, F.F. radi sa promijenljivama
            if(j < i){
                printf(" ");
            }else if((i % 2 == 0) && ((j == n - 2) || (j == n + !(n % 2)))){
                printf("+");
            }else{
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}
