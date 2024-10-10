#include <stdio.h>
/*
 * 1. (6p) Napisati funkciju pom(int arg) koja u zavisnosti od toga da li je broj Fibonačijev kao
povratnu vrednost ima broj koji nastaje izbacivanjem najveće cifre iz broja. Ukoliko broj nije
Fibonačijev, funkcija kao povratnu vrednost ima broj koji nastaje izbacivanjem najmanje cifre
iz broja.
Za sve brojeve koje korisnik unese pozvati funkciju pom. Korisnik unosi brojeve sve dok ne
unese 0.
Primer :Ulaz : 1597 12345 4181 4545 0
Izlaz : 157 2345 411 55 0
Pojašnjenje funkcije pom na primeru :
Broj 1597 je Fibonačijev broj, a najveća cifra u njemu je 9. Novi broj, bez cifre 9 je 157.
Broj 4545 nije Fibonačijev broj, izbacivanjem najmanje cifre dobijamo broj 55.
 */

int jesteFibonacijenv(int broj){
    if(broj == 1 || broj == 0)return 1;
    int f1 = 0;
    int f2 = 1;
    while(f2 < broj){
        int temp = f2;
        f2 = f1 + f2;
        f1 = temp;
        if(f2 == broj) return 1;
    }
    return 0;
}

int obrniBroj(int broj){
    int noviBroj = 0;
    while (broj){
        noviBroj = (noviBroj + broj%10);
        broj /= 10;
        if(broj > 0) noviBroj*= 10;
    }
    return noviBroj;
}



//u zadatku nije napisano da mi zapravo brisemo sve cifre
int izbaciNajveci(int broj){
    int kopija = broj;
    int maxCifra = 0;
    while(kopija){
        if(maxCifra < kopija % 10){
            maxCifra = kopija % 10;
        }
        kopija /= 10;
    }

   int noviBroj = 0;
    while (broj){
        if(maxCifra != broj % 10){
            noviBroj += broj % 10;
        }
        broj /= 10;
        if((broj > 0) && (broj % 10 != maxCifra)){
            noviBroj *= 10;
        }
    }

    return obrniBroj(noviBroj);
}

int izbaciNajmanji(int broj){
    int kopija = broj;
    int minCifra = 999;
    while(kopija){
        if(minCifra > kopija % 10){
            minCifra = kopija % 10;
        }
        kopija /= 10;
    }

    int noviBroj = 0;
    while (broj){
        if(minCifra != broj % 10){
            noviBroj += broj % 10;
        }
        broj /= 10;
        if((broj > 0) && (broj % 10 != minCifra)){
            noviBroj *= 10;
        }
    }

    return obrniBroj(noviBroj);
}

int pom(int arg){
    if(jesteFibonacijenv(arg)){
        return izbaciNajveci(arg);
    }else{
        return izbaciNajmanji(arg);
    }
}

void test(){
    for(int i = 1; i < 500;i++){
        if(jesteFibonacijenv(i)){
            printf("BROJ %d, %d \n",i, jesteFibonacijenv(i));
        }
    }

}


int main() {






    int unos;
    while (1){
        scanf("%d",&unos);
        if(unos == 0) break;
        printf("%d ", pom(unos));
    }
    return 0;
}
