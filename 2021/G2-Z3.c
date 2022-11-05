#include <stdio.h>
#include <stdlib.h>






int main()
{
    int n;
    scanf("%d",&n);
    int max = 2*n+1;
    int granica = max;
    int broj = 0;

    for(int i = 1; i <= max;i++){
        for(int j = 1; j <= max;j++){
            if(j == granica || j == max){
                putchar('*');
            }else if( j > granica){
                    if(j <= max/2+1){
                        printf("%c",'1');
                    }else{
                        printf("%d",broj);
                    }
                }else{
                    putchar(' ');
                }

            }



        if(i < max/2+1){
            granica-=2;
            broj++;
        }else{
            granica+=2;
            broj--;
        }
        putchar('\n');
    }






    return 0;
}
