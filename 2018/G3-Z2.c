#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

///Test primjer:
/// ab123de3000f4g567hh
///OUT: 3004
///bitno koriscenje flag-ova


///brojeve ne gledamo kao brojeve, vec kao karaktere
int main() {
    char ch;
    int zbir = 0;
    int trenutni = 0;
    int flag = 0; ///ako je flag 0, to znaci da je broj validan(nema 6 u sebi)
                  ///ako je flag 1, taj broj ne dodajemo u zbir


    while((ch = getchar()) != '\n'){
        if(ch >=  '0' && ch <= '9'){
            if(ch == '1' || ch == '6'){
                flag = 1;
            }
            trenutni = trenutni * 10 + ch - '0';
        }else{
            if(flag == 0){
                zbir += trenutni;
            }
            trenutni = 0;
            flag = 0;
        }
    }
    if(flag == 0){
        zbir += trenutni;
    }
    printf("%d",zbir);


    return 0;
}
