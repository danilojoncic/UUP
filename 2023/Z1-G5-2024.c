#include <stdio.h>

/*
 * 1. (6p) Napisati funkciju pom(int arg) koja vraća broj dobijen promenom rasporeda cifara prosleđenog
argumenta. Neka je F_n n-ti Fibonačijev broj. U broju koji vraća funcija, sve cifre čiji je F_cifra parno će se
naći levo od svih cifara čije je F_cifra neparno. Sve cifre čije je F_cifra parno će ostati u međusobno istom
poretku kao u učitanom broju, isto važi i za cifre čije je F_cifra neparno.
Napisati program u kome za svaki učitan broj od korisnika treba ispisati rezultat funkcije pom za njega.
Korisnik unosi brojeve sve dok ne unese 0.
Primer: Ulaz : 12345 4482 234 2097 0
Izlaz : 25134 8244 234 2097
Pojašnjenje funkcije pom na primeru:
arg = 12345, F_1 = 1, F_2 = 2, F_3 = 3, F_4 = 5, F_5 = 8
Cifre čije je F_cifra parno su 2 i 5, a neparno 1, 3, 4. Broj koji će da vrati funkcija pom(12345) je 25134,
cifre 2 i 5 nalaze se levo od 1, 3, i 4, i takođe je zadržan poredak između cifara čije je F_cifra parno (ide 2
pa 5) i F_cifra neparno (ide 1, pa 3, pa 4) kao u originalnom broju
 */

int obrniBroj(int broj){
    int noviBroj = 0;
    while (broj){
        noviBroj = noviBroj * 10 + broj % 10;
        broj /= 10;
    }
    return noviBroj;
}

int brojCifara(int unos) {
    int broj = 0;
    while (unos) {
        unos /= 10;
        broj++;
    }
    return broj;
}


int nTiFibonacjievBroj(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    int b1 = 0;
    int b2 = 1;
    int temp;
    while(n){
        temp = b2;
        b2 = b2 + b1;
        b1 = temp;
        n--;
    }
    return b2;
}

int pom(int arg){
    int parni = 0;
    int neparni = 0;
    int potpuniBroj = 0;
    int kopija = arg;


    while (kopija){
        int cifra = kopija % 10;
        if(nTiFibonacjievBroj(cifra) % 2){
            neparni = neparni * 10 + cifra;
        }else{
            parni = parni * 10 + cifra;
        }
        kopija /= 10;
    }
    printf("PARNI: %d , NEPARNI %d  \n", parni,neparni);

    parni = obrniBroj(parni);
    neparni = obrniBroj(neparni);

    int br = brojCifara(neparni);
    int offset = 1;
    while (br){
        offset *= 10;
        br--;
    }
    potpuniBroj = parni * offset + neparni;

    return potpuniBroj;

}

/*trik kako ovaj zadatak da uradimo jeste da imamo 2 odvojena broja jedan
jedan gdje cemo da gomilamo parne fibonaci , a drugi gdje cemo neparne
 na kraju cemo ta 2 broja samo da spojimo
*/
//12345 4482 234 2097 0
int main(){
    int unos;
    while(1){
        scanf("%d",&unos);
        if(unos == 0)break;
        printf("%d ", pom(unos));
    }
    return 0;
}