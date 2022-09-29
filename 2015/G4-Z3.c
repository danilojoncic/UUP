#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///crtanje
int main()
{

    ///formula gornjeg trokuta:
    ///(j < i + 2)
    ///formula donjeg trokuta:
    ///(i < j + 2)

    int n;
    scanf("%d",&n);
    char slovo = 'A';
    char znak = '.';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i < j + 2) && (j < i + 2)){
                putchar(slovo);
            }else{
                putchar(znak);
            }
        }
        printf("\n");
        slovo++;
    }



    return 0;
}
