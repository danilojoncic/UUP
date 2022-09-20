#include <stdio.h>
#include <stdlib.h>

int main(){

    //ch - sluzi za cuvanje trenutnog karaktera
    //prethodni - sluzi za cuvanje prethodnog karaktera kada smo u zagradama, van zagrada nam ne treba
    //            Prethodni je na pocetku 0 jer ni jedan karakter koji ucitavamo ne moze da ima ASCII vrednost 0, ako je prethodni 0 znamo
    //            da trenutni karakter nema prethodnika, sto znaci da je trenutni karakter prvi u toj zagradi
    char ch, prethodni = 0;
    //br_ponavljanja - broj uzastopnih ponavljanja trenutnog karaktera
    //br_ponavljanja_slova - najveci broj uzastopnih ponavljanja slova unutar zagrade
    //br_ponavljanja_cifara - najveci broj uzastopnih ponavljanja cifre unutar zagrade
    //zagrada_flag - flag koj pokazuje da li smo u zagradi ili van nje (1 - unutar zagrada, 0 - van zagrada)
    //proizvod - proizvod najveceg broja uzastopnih ponavljanja slova i najveceg broja uzastopnih ponavljanja cifre unutar te zagrade
    int br_ponavljanja = 0, br_ponavljanja_slova = 0, br_ponavljanja_cifara = 0, zagrada_flag = 0, proizvod = 1;

    while((ch = getchar()) != '\n'){
        //Ako je trenutni karakter zatvorena zagrada, treba da kazemo da nam je flag 0
        if(ch == ']'){
            zagrada_flag = 0;

            //Gledamo da li je karakter pre zatvorene zagrade cifra ili slovo, i poredim broj uzastopnih ponavljanja tog karaktera
            //sa brojem ponavljanja njegove kategorije (ako je prethodni cifra poredim sa maksimalni brojem ponavljanja cifara,
            //                                          ako je prethodni slovo poredim sa maksimalnim brojem ponavljanja za slova)
            if(prethodni >= '0' && prethodni <= '9'){
                if(br_ponavljanja > br_ponavljanja_cifara)
                    br_ponavljanja_cifara = br_ponavljanja;
            }
            else{
                if(br_ponavljanja > br_ponavljanja_slova)
                    br_ponavljanja_slova = br_ponavljanja;
            }

            //Racunam proizvod za trenutnu zagradu i ispisujem ga
            proizvod = br_ponavljanja_slova * br_ponavljanja_cifara;
            printf("%d", proizvod);

            //Pripremam se za sledecu zagradu tako sto sve promenljive stavljam na pocetnu vrednost (jer sam izasao iz zagrade sto znaci
            //                                                                                         da trenutno nisam ni u jednoj zagradi)
            proizvod = 1;
            br_ponavljanja = 0;
            br_ponavljanja_cifara = 0;
            br_ponavljanja_slova = 0;
            prethodni = 0;
        }

        //Ako je zagrada_flag == 1 znamo da smo u zagradi i da treba da gledamo ponavljanja susednih karaktera
        if(zagrada_flag){
            //Ako je prethodni == 0 znamo da smo na prvom karakteru u zagradi, i odmah stavljamo da je prethodni = ch kako ne bismo usli
            //u sledeci if (linija 57)
            if(prethodni == 0)
                prethodni = ch;

            //Ako trenutni karakter nije jednak prethodnom, gledamo broj ponavljanja prethodnog karaktera i  po potrebi azuriramo vrednosti
            //maksimalnih uzastopnih ponavljanja cifara ili slova na isti nacin kao kad smo zatvarali zagradu
            if(prethodni != ch){

                if(prethodni >= '0' && prethodni <= '9'){
                    if(br_ponavljanja > br_ponavljanja_cifara)
                        br_ponavljanja_cifara = br_ponavljanja;
                }
                else{
                    if(br_ponavljanja > br_ponavljanja_slova)
                        br_ponavljanja_slova = br_ponavljanja;
                }
                //Posto smo sada na novom karakteru, stavljamo da je broj ponavljanja za trenutni karakter 0 jer ce se u sledecoj liniji
                //povecati za 1
                br_ponavljanja = 0;
            }

            //Broj uzastopnih ponavljanja trenutnog karaktera povecavamo za 1 i stavljamo da je prethodni karakter sada trenutni
            //kako bismo se spremili za sledecu iteraciju
            br_ponavljanja++;
            prethodni = ch;
            //Radimo continue kako se nista iz zagrade ne bi ispisalo
            continue;
        }

        //Ako je trenutni karakter otvorena zagrada, stavljamo da je zagrada_flag = 1 kako bismo znali da smo u zagradi trenutno
        if(ch == '[')
            zagrada_flag = 1;

        //Ispisujemo trenutni karakter
        putchar(ch);

    }

    return 0;
}
