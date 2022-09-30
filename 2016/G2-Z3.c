#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///crtanje
int main()
{
    int n;
    scanf("%d",&n);
    int granica = n - 1;
    char slovo = 'A';


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            if((j == granica) && (i % 2 == 0)){
                printf("%c",slovo+1);
            }else{
                if((j%2==1) && (i % 2) ){
                    printf("%c",slovo+1);
                }else{
                    putchar(slovo);
                }
            }
        }
        printf("\n");
        if(i % 2 == 1){
            granica--;
            slovo++;
        }
    }


    return 0;
}
