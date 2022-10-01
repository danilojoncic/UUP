#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///crtanje
int main()
{
    int n;
    scanf("%d",&n);
    char slovo = 'A';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){

            if((i + j + n / 2 == n - 1) ||  (j == i - n / 2) ||
               (i + j - n / 2 == n - 1) || (j == i + n / 2)){ ///Uslovni zatvor

                printf("%c",slovo+32);

            }else if(j<=i){
                putchar(slovo);
            }
            else if(j > i){
                    printf("%c",slovo+j-i);
            }
        }
        printf("\n");
        slovo++;
    }
    return 0;
}
