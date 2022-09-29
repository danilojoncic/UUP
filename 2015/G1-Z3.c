#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///crtanje
int main()
{
    int n;
    scanf("%d",&n);
    char znak;


    for(int i = 0; i < n; i++){
        if(i%2){
            znak = '>';
        }else{
            znak = '<';
        }
        for(int j = 0; j < n; j++){
            if((i > j && i + j < n -1) || (i < j && i + j > n - 1)){
                putchar('-');
            }else{
                putchar(znak);
            }
        }
        printf("\n");
    }


    return 0;
}
