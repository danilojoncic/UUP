#include <stdio.h>

/*
 * 1. (6p) Napisati funkciju pom(int arg) koja proverava da li se uneti završava sa dve cifre od kojih (u bilo
kom poretku) može da se sastavi dvocifren prost broj. Ako ovo svojstvo važi, funkcija vraća taj prost broj,
a ako ne važi, vraća prvi prost broj veći od oba proverena dvocifrena broja. Ako su oba broja koja se
mogu sastaviti od poslednjih cifara broja arg prosta, funkcija vraća veći od njih. U glavnom programu se
unosi broj n i n brojeva za koje treba ispisati rezultate funkcije pom. Ograničenje: uneti brojevi se ne
završavaju sa 00 (tj. može da se sastavi bar jedan dvocifren broj od poslednje dve cifre).
Primer: Ulaz: 6 111 132 223 118 240 254
Izlaz: 11 23 23 83 41 59
Objašnjenje: 111: 11 je prost broj, 132 - proveravaju se 32 i 23, 23 je prost, slično za 223. 118:
proveravaju se 18 i 81, 83 je prvi prost broj veći od oba. 40 - proverava se 40, prvi veći prost broj je 41.
254: proveravaju se 45 i 54, prvi već prost broj je 59.
 */

int jesteProst(int unos) {
    if (unos < 2) return 0;
    for (int i = 2; i <= unos / 2; i++) {
        if (unos % i == 0) return 0;
    }
    return 1;
}

int nadjiVeciOdDva(int prvi, int drugi) {
    //ovo je dobro da se nacrta na brojevnoj pravoj
    int broj = (prvi > drugi) ? prvi + 1 : drugi + 1;
    while (1) {
        if (jesteProst(broj)) break;
        broj++;
    }
    return broj;
}



int pom(int arg) {
    int broj1 = arg % 10;
    int broj2 = (arg / 10) % 10;

    int poredak1 = broj1 * 10 + broj2;
    int poredak2 = broj2 * 10 + broj1;

    if (jesteProst(poredak1) && jesteProst(poredak2)) {
        //oba su prosta
        return (poredak1 > poredak2) ? poredak1 : poredak2;
    } else if (jesteProst(poredak1)) {
        //prvi poredak je prost
        return poredak1;
    } else if (jesteProst(poredak2)) {
        //drugi poredak je prost
        return poredak2;
    } else {
        //nema prostih sto znaci moramo da nadjemo
        return nadjiVeciOdDva(poredak1, poredak2);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int unos;
        scanf("%d",&unos);
        printf("%d ", pom(unos));
    }
    return 0;
}