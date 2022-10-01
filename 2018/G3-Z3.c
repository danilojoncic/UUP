#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main() {

    int n;
    scanf("%d",&n);
    int broj = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j != i && i+j != n + 1){
                broj+=i;
                printf("%d\t",broj);
            }else{
                printf("0\t");
            }
        }
        printf("\n");
    }


    return 0;
}

