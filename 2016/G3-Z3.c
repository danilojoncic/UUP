#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///crtanje
int main()
{
    int n;
    scanf("%d",&n);
    char broj = '1';
    int borderEnd = n-1;
    int borderMid;


    for(int i = 0; i < n;i++){
        for(int j = 0; j < n; j++){
            if((i % 2) && ((j == borderEnd) || (j == n/2) || (j == n / 2 - 1))){
            printf("%c",broj+2);
            }
            else{
                putchar(broj);
            }
        }

        printf("\n");
        broj++;
    }

    return 0;
}
