#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main() {

    int n;
    scanf("%d",&n);
    char zvezda = '*';
    char caps = '^';
    char plus = '+';
    char eq = '=';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i+j+n/2<n-1) || (j<i-n/2) || (j > i+n/2) || (i+j-n/2 > n-1)){
                putchar(zvezda);
            }else if((i+j+n/2 == n-1) || (j == i-n/2) || (i+j-n/2 == n-1) || (j == i+n/2)){
                putchar(caps);
            }else if(i % 2 == 1){
                putchar(plus);
            }else if(i > 0 && i % 2 == 0){
                putchar(eq);
            }
        }
        printf("\n");
    }
    return 0;
}

