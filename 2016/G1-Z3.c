#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///crtanje
int main()
{

    int n;
    int broj = 1;
    scanf("%d",&n);

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){
            if(broj > n){
                broj = 1;
            }
            if(i % 2 == 0){
            printf(" %d ",broj);
            broj++;

        }else{
            if(j % 2 == 0){

                printf(" %d ",broj);

            }else{
                broj++;
                printf(" %d ",broj);
                broj--;
            }
        }
    }
        printf("\n");
        if(i % 2){
            broj++;
        }


    }


    return 0;
}
