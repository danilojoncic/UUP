#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int pom(int arg){
   //koliko broj ima parnih cifara
   int unos = arg;
   int brojac = 0;
   while(unos){
     int trenutni = unos % 10;
     if(trenutni % 2 == 0){
        brojac++;
     }
     unos /= 10;
   }
   return brojac;
}





int main()
{   ///MORA DA BUDE MOGUCE!!!
    int unos;
    int zbir = 0;
    while(1){
        scanf("%d",&unos);
        if(unos == 0){
            break;
        }else{
            if(pom(unos) % 2){
                zbir += pom(unos);
            }
        }
    }
    printf("%d", zbir);

    return 0;
}
