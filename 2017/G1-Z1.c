#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pom(int arg, int delilac)
{
    //92643 po specifikaciji zadatka ovdje se trazi da li su brojevi unutar dijeljivi sa 3
    //963
    int rezultat = 0;
    int i = 1;
    while(arg){
        int cifra = arg % 10;
        if(cifra % delilac){
            arg /= 10;
            continue;
        }
        rezultat += cifra * i;
        i *= 10;
        arg /= 10;
    }
    return rezultat;
}

int main()
{
    int pocetak,kraj;
    int delilac = 3;

    scanf("%d%d",&pocetak,&kraj);
    for(int i = pocetak; i <= kraj; i++){
        if(i == pom(i,delilac)){
            printf("%d ",i);
        }
    }

    return 0;
}
