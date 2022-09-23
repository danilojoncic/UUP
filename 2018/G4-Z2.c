#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


///unos ab123de3000f4g567hh
///izlaz 690
///izracunati zbir svih brojeva koi sadrze samo neparne cifre
int sadrzi(int unos){
    int flag = 0;
    int br;
    int broj = unos;
    while(broj){
        br = broj % 10;
        if(br % 2){
            flag = 1;
        }else{
            flag = 0;
            return flag;
        }
        if(br == 0){
            flag = 0;
            return flag;
        }
        broj/=10;
        printf(" flag: %d \n",flag);
    }
    return flag;
}

int brojCif(int a){
    int unos = a;
    int counter = 0;
    while(unos){
        unos/=10;
        counter++;
    }
    return counter;
}

///vjerovatno greska u zadatku pa su neparne cifre ,
///mozda su mislili na neparan broj cifara





int main() {

    int res = 0;
    int broj = 0;
    char ch;
    int rezultat = 0;

    while((ch = getchar()) != '\n'){
        if(ch >= 'a' && ch <= 'z'){
            if(brojCif(broj) % 2){
                rezultat += broj;
            }

            broj = 0;
            continue;
        }
        if(ch >= '0' && ch <= '9'){
            broj = broj * 10 + ch - '0';
        }
        printf("  broj : %d , rezultat %d\n",broj,rezultat);
    }
    printf("%d",rezultat);




    return 0;
}
