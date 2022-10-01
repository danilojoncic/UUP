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
            if((i == 1 && j < n+1) || (i <=n && j < 2) || (i == n && j <=n) || (i <=n && j == n))  {
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

