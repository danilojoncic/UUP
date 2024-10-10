    #include <stdio.h>

    /*
     * 1. (6p) Napisati funkciju pom(int arg) koja proverava da li uneti broj počinje sa dve cifre od kojih (u bilo
    kom poretku) može da se sastavi dvocifren prost broj. Ako ovo svojstvo važi, funkcija vraća taj prost broj,
    a ako ne važi, vraća najveći prost broj manji od oba proverena dvocifrena broja. Ako su oba broja koja se
    mogu sastaviti od poslednjih cifara broja arg prosta, funkcija vraća manji od njih. U glavnom programu se
    unosi broj n, a zatim n brojeva za koje je potrebno ispisati rezultate funkcije pom. Ograničenje:
    podrazumevati da su svi brojevi koje korisnik unosi veći ili jednaki 10, tj. barem dvocifreni.
    Primer: Ulaz: 5 132 328 789 444 969
    Izlaz: 13 23 73 43 67
    Objašnjenje: 132: 13 je prost broj, 328 - proveravaju se 32 i 23, 23 je prost. 789: proveravaju se 78 i 87,
    73 je prvi prost broj manji od oba. 444 - proverava se 44, prvi manji prost broj je 43. 969: proveravaju se
    96 i 69, prvi manji prost broj je 67.
     */

    int jesteProst(int unos) {
        if (unos < 2) return 0;
        for (int i = 2; i <= unos / 2; i++) {
            if (unos % i == 0) return 0;
        }
        return 1;
    }

    int nadjiManjiOdDva(int prvi, int drugi) {
        //ovo je dobro da se nacrta na brojevnoj pravoj
        int broj = (prvi < drugi) ? prvi - 1 : drugi - 1;
        while (broj) {
            if (jesteProst(broj)) break;
            broj--;
        }
        return broj;
    }

    int brojCifara(int unos){
        int br = 0;
        while (unos){
            unos /= 10;
            br++;
        }
        return br;
    }

    int stepen(int a, int b){
        int rez = 1;
        while(b){
            rez *= a;
            b--;
        }
        return rez;
    }



    int pom(int arg) {
        int broj = arg / stepen(10, brojCifara(arg)-2);
        int broj1 = broj % 10;
        int broj2 = broj / 10 % 10;

        int poredak1 = broj1 * 10 + broj2;
        int poredak2 = broj2 * 10 + broj1;

        if (jesteProst(poredak1) && jesteProst(poredak2)) {
            //oba su prosta
            return (poredak1 < poredak2) ? poredak1 : poredak2;
        } else if (jesteProst(poredak1)) {
            //prvi poredak je prost
            return poredak1;
        } else if (jesteProst(poredak2)) {
            //drugi poredak je prost
            return poredak2;
        } else {
            //nema prostih sto znaci moramo da nadjemo
            return nadjiManjiOdDva(poredak1, poredak2);
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