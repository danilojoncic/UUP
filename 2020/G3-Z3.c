#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);

    //Leva granica krece od pocetka matrice, a desna od kraja matrice
    //Po granicama cemo gledati sta treba da ispisemo gde
    int leva_granica = 0, desna_granica = n-1;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){

            //Ako smo trenutno na levoj ili desnoj granici, ispisujemo "^"
            if(j == leva_granica || j == desna_granica)
                printf("^");
            //Ako smo izmedju granica treba da ostavimo prazan prostor, pa cemo ispisivati " "
            else if(j > leva_granica && j < desna_granica)
                printf(" ");
            //Ako nismo usli u prethodne if-ove, znamo da smo van granica (levo od leve granice
            //ili desno od desne granice), svi uslovi unutar elsa se odnose na te pozicije u matrici
            else{
                //Ako smo u prvoj ili poslednjoj koloni trenutnog reda i broj reda je paran, ispisujemo *
                if((j == 0 || j == n-1) && i%2 == 0)
                    printf("*");

                //Ako smo u prvoj ili poslednjoj koloni trenutnog reda i broj reda je neparan, ispisujemo -
                else if((j == 0 || j == n-1) && i%2 == 1)
                    printf("-");

                //Ako smo izmedju prve kolone i leve granice, ispisujemo "("
                else if(j > 0 && j < leva_granica)
                    printf("(");
                //Ostaje jos slucaj kada smo izmedju desne granice i poslednje kolone i tada ispisujemo ")"
                else
                    printf(")");
            }

        }
        printf("\n");

        //Ako je broj redova paran i dosli smo do sredine, preskacemo pomeranje granica kako bi sledeci
        //red bio isti
        if(i == n/2 - 1 && n % 2 == 0)
            continue;

        //Ako smo u redu koji je pre polovine matrice, levu i desnu granicu priblizavamo jednu drugoj
        if(i < n/2){
            leva_granica++;
            desna_granica--;
        }
        //Ako smo u redu koji je pre polovine matrice, levu i desnu granicu udaljavamo jednu od druge
        else{
            leva_granica--;
            desna_granica++;
        }

    }

    return 0;
}

