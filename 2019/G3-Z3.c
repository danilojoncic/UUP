#include <stdio.h>
#include <stdlib.h>







int main()
{

    int n;
    scanf("%d",&n);
    char slovo = 'A'+n-1;
    char slovo2 = 'A';

    for(int i = 1;i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i%2) && (i+j == n+1)){
                    printf("%c",slovo2+i-1);

            }else if((i%2 == 0) && (i+j == n+2)){
                    printf("%c",slovo2+i-1+32);
                }else putchar(slovo);
            }

        printf("\n");
        slovo--;
    }




    return 0;
}
