#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxCifra(int arg){
    int max = 0;
    while(arg){
        if(max < arg % 10){
            max = arg % 10;
        }
        arg /= 10;
    }
    return max;
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
    int max = maxCifra(arg);
    int trenutnaCifra;
    int dobijenBroj = 0;
    int unos = arg;
    int predjeni = 0;
    while(unos){
        trenutnaCifra = unos % 10;
        if(trenutnaCifra < max){
            dobijenBroj += trenutnaCifra * stepen(10,predjeni-1);
            predjeni++;
            unos /= 10;
        }else{
            predjeni++;
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
    int razlika;
    while(1){
        scanf("%d",&n);
        if(n == 0){
            break;
        }else{
            razlika = n - pom(n);
            printf("unos : %d, pom: %d, razlika : %d \n",n,pom(n), razlika);

        }

    }

    return 0;
}
