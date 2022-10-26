#include <stdio.h>
#include <stdlib.h>






int main()
{
    int n;
    scanf("%d",&n);
    int broj = 1;
    int granica = 1;
    int max = 2*n+1;
    for(int i = 1; i <= max;i++){
        for(int j = 1; j <= granica;j++){
            if(j == granica || j == 1){
                putchar('*');
            }else{
                if(j < granica/2+1){
                    printf("%d",broj++);
                }else{
                    printf("%d",broj--);
                }
            }
        }
        broj = 1;
        if(i<max/2+1){
            granica+=2;
        }else{
            granica-=2;
        }
        putchar('\n');
    }
    return 0;
}
