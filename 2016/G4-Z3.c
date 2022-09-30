#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///crtanje
int main()
{
    int n;
    scanf("%d",&n);
    char broj = '1';
    int dijagonala = 0;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){
            if(((i > 0) && (i < n-1)  && (j == dijagonala))){
                printf("%c",broj+1);
            }else if((i == 0 && j == n-1)  || (i == n-1 && j == 0)){
                printf("%c",broj+1);
            }else{
                putchar(broj);
            }
        }
        printf("\n");
        broj++;
        dijagonala++;
    }

    return 0;
}
