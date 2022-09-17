#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int zameniNajmanjom(int arg,int x){
    ///Dio koda za pronalazak najmanje cifre!!!
    int najmanjaCifra = INT_MAX;
    int tmp = arg, cifra;
    while(tmp > 0){
        cifra = tmp % 10;
        if(cifra < najmanjaCifra){
            najmanjaCifra = cifra;
        }
        tmp /= 10;
    }
    ///

    ///Dio koda za sastavljanje novog broja!!!
    int novi_broj = 0,brojac = 1;

    while(arg > 0){
        x--;
        cifra = arg % 10;
        if(x == 0){
            novi_broj = najmanjaCifra * brojac + novi_broj;
        }else{
            novi_broj = cifra * brojac + novi_broj;
        }
        arg /= 10;
        brojac *= 10;
    }
    return novi_broj;
    ///
}


int main() {

    int a,b;
    scanf("%d%d",&a,&b);
    int zamijenjenBroj;
    for(int i = a; i < b; i++){
        zamijenjenBroj = zameniNajmanjom(i,3);    ///uslov zadatka da se ne mijenja cifra na mjestu stotice
        if(zamijenjenBroj != i){
            printf("%d ,", i);
        }else{
            continue;
        }
    }
    return 0;
}
