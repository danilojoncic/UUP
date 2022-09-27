#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


///UNOS : ab13(12s3)(5)x(y6gg79zs)pk8
///IZLAZ : 137
/// jer 12s3 -> 1 3 -> 13
///ispisati zbir brojeva koji se dobju sastavljanjem prve i poslednje cifre unutar zagrada


int vratiPrvuCifru(int a){
    int unos = a;
    int res = 0;
    while(unos){
        res = unos;
        unos/= 10;
    }
    return res;
}



int main() {
    int broj = 0;
    int res = 0;
    char ch;
    char zagrada = 0;

    while((ch = getchar()) != '\n'){
        if(ch == '('){
            zagrada = 1;
           }
        if(ch == ')'){
            if(broj < 10){
                res += broj * 10 + broj;
            }else if(broj > 10){
                res += vratiPrvuCifru(broj) * 10 + broj % 10;
        }
            zagrada = 0;
            broj = 0;
        }
        if((zagrada == 1) && (ch >= '0' && ch <= '9')){
            broj = broj * 10 + ch - '0';
        }
    }
    printf("%d", res);

    return 0;
}




///Prethodni pokusaj:
/*
int main() {
    char ch;
    char prev;
    int broj = 0;
    int rezultat = 0;
    int mys = 0;

    ///ab13(12s3)(5)x(y6gg79zs)pk8
    prev = getchar();
    while((ch = getchar()) != '\n'){

        if((prev == '(') && (ch >= '0' && ch <= '9')){
            broj = broj * 10 + ch - '0';

        }
        if((prev >= '0' && prev <= '9') && (ch == ')')){
            broj = broj * 10 + prev - '0';
            rezultat+=broj;
        }
        if((prev == ')')  && ch != prev){
            broj = 0;
        }


        ///poseban slucaj : (y6gg79zs)











        printf(" prev = %c , ch = %c , broj = %d, rez =  %d\n",prev,ch, broj,rezultat);
        prev = ch;
    }
    if(mys){
       rezultat = rezultat + (broj / brCifara(broj) ) * 10 + broj % 10;
    }
    printf("%d",rezultat);



    return 0;
}
*/
