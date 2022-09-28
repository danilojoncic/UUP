#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int a, int b){
    return a < b ? a : b;
}



///Poenta kod ovih zadataka jeste naci vezu izmedju
///nacrtane figure i unosa (n), indexa i , j;

int main()
{
    int i, j, n;
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(j <= n / 2){
                printf("%d", min(min(i, n - i + 1), min(j, n - j + 1)));     //  Gornja i donja polovina levog dela.
            }
            else{
                printf("%d", min(i, n - i + 1));    //  Desna polovina.
            }
        }
        printf("\n");
    }
    return 0;
}

