#include <stdio.h>
#include <stdlib.h>

/**
UUP-2018-2019-KLK1-G1-Z1
1 (6p). Napisati funkciju int pom(int arg) koja vraća broj koji se dobije kada se iz argumenta arg
izbace sve proste cifre. Za određivanje da li je cifra prosta napisati dodatnu funkciju int prost(int
n) koja vraća 1 ukoliko je broj n prost, ili 0 ukoliko je n složen broj. Zatim korišćenjem funkcije pom
ispisati sve brojeve iz intervala koji unosi korisnik koji imaju sve proste cifre. Napomena: 0 i 1 se ne
ubrajaju u proste brojeve!

primer: 1 100
izlaz: 2 3 5 7 22 23 25 27 32 33 35 37 52 53 55 57 72 73 75 77
*/


int prost(int n) {
    for (int i = 2; i < n; i++)
        if (n%i == 0)
            return 0;

    return 1;
}

int pom(int arg) {
    int cifra;
    int noviBr = 0;
    int p = 1;


    while(arg) {

        cifra = arg%10;

        if (cifra == 0 || cifra == 1) {
            arg /= 10;
            continue;
        }


        if (prost(cifra) == 0) {
            noviBr += cifra*p;
            p *= 10;
        }
        arg /= 10;
    }

    return noviBr;
}

int main() {
    int a, b;

    scanf("%d%d", &a, &b);

    for(; a <= b; a++) {
        // Treba da prikažemo brojeve koji imaju sve proste cifre, što znači da će funkcija pom
        // vratiti nula, jer ona izbacuje sve cifre koje su proste, tako da će broj ostati bez cifara.
        if (!pom(a)) {
            // Rezultat će biti nula i ako broj ima cifru 0 ili 1 u sebi (i ostale proste brojeve),
            // a u zadatku piše da 0 i 1 nisu prosti prosti brojevi, što znači da moramo
            // da proverimo da li je rezultat imao te cifre jer taj broj ne možemo ispisati. Ako jeste,
            // flag će nam biti jedan i u tom slučaju nećemo ispisati broj.
            int flag = 0;
            int copy = a;
            while (copy) {
                if (copy%10 == 0 || copy%10 == 1) {
                    flag = 1;
                    break;
                }
                copy /= 10;
            }
            if (!flag)
                printf("%d ", a);
        }
    }
}
