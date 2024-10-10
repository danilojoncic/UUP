#include <stdio.h>

/*
 * 1. (6p) Napisati funkciju pom(int arg) koja svaku cifru iz arg ciklično povećava za k. k je n-ti po redu prost
broj, a n predstavlja sumu cifara koje se nalaze na prvoj polovini broja arg (ako arg ima neparan broj
cifara, onda se i cifra u sredini dodaje u sumu). Ciklično povećanje cifre znači da posle 9 ponovo dolazi 0.
Ispisati rezultate pom funkcije svih brojeva koje korisnik unese. Korisnik unosi brojeve sve dok ne unese
0.
Primer: Ulaz: 111 234 352781 4554119 0
Izlaz: 444 345 241670 5665220
Objašnjenje:
pom(111): n je 2, drugi po redu prost broj je 3, stoga se svaka cifra broja 111 ciklično povećava za 3,
dakle 444
pom(234): n je 5, peti po redu prost broj je 11, onda se svaka cifra broja 234 povećava za 11 - povećanje
je ciklično, znači 9 ciklično povećano za 1 daje 0, ako je povećano za 2 daje 1… Cifra 2 ciklično povećana
za 11 bi trebalo da vrati 3, za 3 vraća 4, za 4 vraća 5.
 */
int brojCifara(int unos) {
    int broj = 0;
    while (unos) {
        unos /= 10;
        broj++;
    }
    return broj;
}

int obrni(int broj){
    int rez = 0;
    while (broj) {
        rez= rez * 10 + broj % 10;
        broj /= 10;
    }
    return rez;
}

int sumaCifaraPrvePolovine(int unos) {
    int brCifara = brojCifara(unos);
    int granica = (brCifara % 2) ? brCifara / 2 + 1 : brCifara / 2;

    int br = 0;
    int suma = 0;
    int obrnut = obrni(unos);


    while (obrnut) {
        if (br < granica) {
            suma += obrnut % 10;
        }
        obrnut /= 10;
        br++;
    }

    return suma;
}

int jeProst(int unos) {
    if (unos < 2) return 0;
    for (int i = 2; i <= unos / 2; i++) {
        if (unos % i == 0) return 0;
    }
    return 1;
}

int nTiProstiBroj(int n) {
    int broj = 2;
    int count = 0;

    while (1) {
        if (jeProst(broj)) {
            count++;
            if (count == n) {
                return broj;
            }
        }
        broj++;
    }
}

int pom(int arg) {
    int suma = sumaCifaraPrvePolovine(arg);
    int k = nTiProstiBroj(suma);

    int noviBroj = 0;
    int stepen = 1;

    while (arg) {
        int cifra = arg % 10;
        cifra = (cifra + k) % 10;  // Ciklicno, ovo bi bilo dobro nacrtati

        noviBroj = cifra * stepen + noviBroj;
        stepen *= 10;
        arg /= 10;
    }

    return noviBroj;
}

int main() {
    int unos;
    while (1) {
        scanf("%d", &unos);
        if (unos == 0) break;
        printf("%d ", pom(unos));
    }

    return 0;
}
