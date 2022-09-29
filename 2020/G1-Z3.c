#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///crtanje
int main()
{
    int n;
    scanf("%d",&n);
    int leva = 0, desna = n - 1;
    char unutra;
    char spolja = 'a' - 1;


    for(int i = 0;i< n; i++){
        unutra = 'a';
        for(int j = 0 ; j < n; j++){
           if(j > leva && j < desna){
                printf("%c",unutra);
                if(n % 2 == 0 && j == n / 2 - 1){
                    continue;
                }
                    if(j < n / 2){
                        unutra++;

                    }else{
                        unutra--;
                        }
                    }
           else if(j == leva || j == desna){
                if( i == n / 2 || (n % 2 == 0 && i == n / 2 - 1)){
                    printf("*");
                }else if(j == leva){
                    printf(">");
                }
                 else if(j == desna){
                    printf("<");
                }
           }else{
               if(j < leva){
                    putchar(spolja);
                    spolja--;


               }else{
                    putchar(++spolja);

               }
           }
        }
        printf("\n");
        if(n % 2 == 0 && i == n / 2 - 1){
            continue;
        }

        if(i < n / 2){
            spolja++;
            leva++;
            desna--;
        }else{

            leva--;
            desna++;
        }
    }

    return 0;
}
