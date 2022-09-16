#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int stepen(int unos,int stepenik){
    int rezultat = 1;
    for(int i = stepenik; i > 0; i--){
        rezultat *= unos;
    }
    return rezultat;

}

int brojCifara(int broj){
    int brojac = 0;
    while(broj){
        broj/= 10;
        brojac++;
    }
    return brojac;

}


int pom(int arg){
    int unos = arg;
    int broj_bez_poslijednjeg_broja = unos / 10;
    int ostatak = 0;
    printf("unos je %d \n",unos);
    ostatak = broj_bez_poslijednjeg_broja % stepen(10,brojCifara(broj_bez_poslijednjeg_broja)-1);
    printf("broj cifara broja bez poslijednje cifre %d, je %d \n",broj_bez_poslijednjeg_broja,brojCifara(broj_bez_poslijednjeg_broja));
    printf("ostatak %d\n",ostatak);
    return ostatak;

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
            zbir += pom(unos);
        }

    }
    printf("\n zbir : %d ",zbir);

    return 0;
}
