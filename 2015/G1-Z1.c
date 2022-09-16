#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int pom(int arg){
    int unos = arg;
    int flagTrue = -1;
    int trenutniBroj = 0;
    while(unos){
        trenutniBroj = unos % 10;
        if(trenutniBroj < 5){
            flagTrue = 1;
        }else{
            flagTrue = 0;
        }
        unos /= 10;
    }

    return flagTrue;
}


int main()
{   ///MORA DA BUDE MOGUCE!!!
    // 1 2 3 4 5 6 7 8 9 10
   int a,b;
   int proizvod = 1;
   scanf("%d%d",&a,&b);
   for(int i = a; i <= b; i++){
        if(pom(i) && (i%2 == 0)){
            proizvod *= i;
        }
   }
   printf("%d", proizvod);

    return 0;
}
