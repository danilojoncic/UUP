#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main() {

    int n;
    scanf("%d",&n);
    int prvi = 1;
    int drugi = 1;
    int zbir;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j || i + j == n + 1){
                printf("%d \t",prvi);
                zbir = prvi + drugi;
                prvi = drugi;
                drugi = zbir;
            }else{
                printf("0\t");
            }
        }
        printf("\n");
    }


    return 0;
}

