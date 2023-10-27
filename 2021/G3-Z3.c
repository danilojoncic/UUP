#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    char slovo = 'A';
    char slovo2 = slovo;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i > j && i + j < n - 1) || (i < j && i + j > n - 1)){
                printf("%c",slovo + 32);
            }else{
                printf("%c",slovo2);
            }
        }
        printf("\n");
        slovo++;
        if(n%2 == 1){
            if(i < n/2){
                slovo2+=i+1;
            }else{
                slovo2-=n-i-1;
            }
        }else{
            if( i < n/2-1 ){
                slovo2+=i+1;
            }else{
                if(i == n / 2-1){
                    continue;
                }else{
                    slovo2-=n-i-1;
                }
            }
        }
    }
    return 0;
}

