#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


///unos ab123de3000f4g567hh
///izlaz 690

int sadrzi(int unos,int sadrzanik){
    int un = unos;
     int flag = 0;
    while(un){
        if(sadrzanik == un % 10){
            flag = 1;
        }
        un /= 10;
    }
    return flag;
}





int main() {

    int res = 0;
    int broj = 0;
    char ch;
    int rezultat = 0;

    while((ch = getchar()) != '\n'){
        if(ch >= 'a' && ch <= 'z'){
            if(sadrzi(broj,2) || sadrzi(broj,5)){
                rezultat += broj;
            }

            broj = 0;
            continue;
        }
        if(ch >= '0' && ch <= '9'){
            broj = broj * 10 + ch - '0';
        }
        printf("  broj : %d\n",broj);
    }
    printf("%d",rezultat);




    return 0;
}
