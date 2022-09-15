#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int brojCifara(int n){
    int brojCifara = 0;
    while(n > 0){
        n /= 10;
        brojCifara++;
    }
    return brojCifara;
}

double aritmetickaSredina(int n, int m){
    int brCifara = brojCifara(n); //promijenljiva brCifara ima vrijednost broja cifri od n,
                                  //koristeci funkciju brojCifara koju smo gore napisali
    int brojac = pow(10,brCifara - 1);
    double zbirCifara = 0;
    int cifra;
    int temp = m;

    //n = 400
    //brojac = 100;
    //cifra = 4, n / broj -> 400/100

    while(temp > 0){
        cifra = n/brojac;
        temp--;
        zbirCifara += cifra;
        n = n % brojac; // -> n =12345678,brojac = 10000000, cifra = 1, -> 1 (2345678)
        brojac /= 10;
        //citav ovaj kod sa while, nam sluzi da bi izolovali brojeve sa lijeva,
    }
    double aritmeticka = zbirCifara / m;
    return aritmeticka;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i = n; i < m; i++){
        if(aritmetickaSredina(i,2) < brojCifara(i)){
            printf("%d ",i);
        }
    }


    return 0;
}
