#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

///Primer: ab13[12s3][5]x[y6gg79zs]pk8
///Ispis: 3
/*
Objasnjenje: [12s3] – prva cifra je 1, poslednja 3, razlika 2
[5] – prva cifra je 5, poslednja cifra je 5, razlika 0
[y6gg79zs] – prva cifra je 6, poslednja cifra je 9, razlika 3
Najveca razlika je 3.
*/

///zadatak sa pamcenjem da li su zagrade zatvorene ili ne
///brojeve ne gledamo kao brojeve, vec kao karaktere
int main() {

    char ch;
    int max_razlika = INT_MIN;
    int prvaCifra = -1;
    int poslednjaCifra = -1;
    int zagradaFlag = 0;
    int trenutna_razlika = 0;

    //ab13[12s3][5]x[y6gg79zs]pk8
    while((ch = getchar()) != '\n'){

        if(ch == '['){
            zagradaFlag = 1;
            continue;
        }

        if((ch >= '0' && ch <= '9') && zagradaFlag == 1){   //ako nam je karakter cifra i ako se nalazimo u zagradi
            if(prvaCifra == -1){   // ideja da se prva cifra samo jedanput upise
                prvaCifra = ch - '0'; //pretvaranje karaktera cifre u broj
            }
            poslednjaCifra = ch - '0';
            continue;
        }

        if(ch == ']'){
           zagradaFlag = 0;
           trenutna_razlika = abs(prvaCifra - poslednjaCifra);
           if(trenutna_razlika > max_razlika){
                max_razlika = trenutna_razlika;
            }
            prvaCifra = -1;       //resetovanje vrijednosti da bi u iducoj zagradi mogli da radimo
            poslednjaCifra = -1;  // isto
        }
    }
    printf("%d ", max_razlika);



    return 0;
}
