#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int stepen(int a, int stepenik){
    int rezultat = 1;
    if(stepenik > 0){
     while(stepenik){
        rezultat *= a;
        stepenik--;
     }
    }else{
        rezultat = 1;
    }
    return rezultat;
}

int pom(int arg,int delilac){ //delilac je u opsegu od 2 do 9
    int brojDobijen = 0; // broj koji se dobije kada se iz broja izbace sve cifre deljive deliocem
    int trenutniBroj;
    int brojPredjenih = 0;
    int unos = arg;
    while(unos){
        trenutniBroj = unos % 10;
        if(trenutniBroj % delilac){
            brojDobijen += trenutniBroj * stepen(10,brojPredjenih);
            brojPredjenih++;
            unos /= 10;
        }else{
            unos /= 10;
            continue;
        }
    }
    if(brojDobijen > delilac){
        return brojDobijen;
    }
}




int main()
{   ///MORA DA BUDE MOGUCE!!!
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i = a; i <= b; i++){

        printf(" %d ,",pom(i,2)); // ispisi sve brojeve iz intervala koji nemaju ni jednu parnu cifru

    }

    return 0;
}
