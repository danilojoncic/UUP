#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int brojCifara(int broj){
    int temp = broj;
    int brojac = 0;
    while(temp){
        temp/= 10;
        brojac++;
    }
    printf("broj cifara broja: %d je %d ",broj,brojac);
    return brojac;
}

int obrniBroj(int broj){
    int unos = broj;
    int ostatak = 0;
    int zbir = 0;
    int stepen = brojCifara(broj);
    while(unos){
        ostatak = unos % 10;
        zbir += ostatak * pow(10,stepen - 1);
        unos /= 10;
        stepen--;
    }
    printf(" obrnuti broj : %d \n",zbir);
    return zbir;
}



int pom(int arg){
    int flagTrue = -1;
    if(arg > obrniBroj(arg)){
        flagTrue = 1;
    }else{
        flagTrue = 0;
    }
    printf("flag :  %d \n",flagTrue);
    return flagTrue;
}




int main()
{   ///MORA DA BUDE MOGUCE!!!
   int unos;
   int zbir = 0;
   while(1){
    scanf("%d",&unos);
    if(pom(unos)){
        zbir += unos;
     }
    if(unos == 0){
        break;
    }
   }
   printf("zbir :  %d \n", zbir);

    return 0;
}
