#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int minCifra(int arg){
    int min = arg;
    while(arg){
        if(min > arg % 10){
            min = arg % 10;
        }
        arg /= 10;
    }
    return min;
}



int brojCifara(int arg){
    int counter = 0;
    int num = arg;
    while(num){
        num/=10;
        counter++;
    }
    return counter;

}

int stepen(int a,int stepenik){
    int rezultat = 1;
    if(stepenik == 0){
        rezultat = 1;
    }else{
        while(stepenik){
            rezultat *= a;
            stepenik--;
        }
    }
    return rezultat;

}


int pom(int arg){
    int trenutnaCifra;
    int dobijenBroj = 0;
    int unos = arg;
    int min = minCifra(unos);
    int predjeni = 0;
    while(unos){
        trenutnaCifra = unos % 10;
        if(trenutnaCifra != min){
            dobijenBroj += trenutnaCifra * stepen(10,predjeni);
            predjeni++;
            unos /= 10;
        }else{
            //predjeni++;
            unos /= 10;
            continue;
        }

    }
    //printf("%d ", dobijenBroj);
    return dobijenBroj;
}




int main()
{   ///MORA DA BUDE MOGUCE!!!
    int n;
    int zbir;
    while(1){
        scanf("%d",&n);
        if(n == 0){
            break;
        }else{
            zbir = n + pom(n);
            printf("unos : %d, pom: %d, zbir : %d \n",n,pom(n), zbir);

        }

    }

    return 0;
}
