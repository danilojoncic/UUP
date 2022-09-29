#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///crtanje
int main()
{

    ///Formula za odnose crtica
    ///lijeve crtice j < (n - i) / 2
    ///desne crtice j > (n + i) / 2

    int n;
    scanf("%d",&n);

    char znak = '-';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < (n - i) / 2){
                putchar(znak);
            }else if(j > (n + i) / 2){
                putchar(znak);
            }else{
                putchar('A' + j );
            }
        }
        printf("\n");

    }



    return 0;
}
