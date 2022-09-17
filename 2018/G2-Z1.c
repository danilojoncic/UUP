#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int brojCifara(int n){
    int unos = n;
    int broj = 0;
    while(unos){
        unos /= 10;
        broj++;
    }
    return broj;
}

int posC(int n){
    int pon = brojCifara(n);
    int unos = n;
    int del = pow(10,pon-1);
    int rezultat = unos / del;
    return rezultat;
}


int pom(int n){
    int unos = n;
    int prva = unos % 10;
    int pos = posC(n);
    //printf("prva D : %d, pos L: %d \n",prva, pos);
    int rezultat = (prva * pos) * (prva * pos);
    //printf("kvadrat proizvoda : %d \n", rezultat);
    return rezultat;
}
int zbirDel(int n){
    int zbir = 0;
    for(int i = 1; i < n ; i++){
        if((n % i) == 0){
            zbir += i;
        }
    }
    //printf("zbir : %d \n",zbir);
    return zbir;
}

int obilan(int n){
    return ( n < zbirDel(n))? 1 : 0;
}


int main() {
    ///Sad se prekrstimo 3 puta i molimo boga da li radi!!!
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i = a; i <=b; i++){
        if(obilan(i) && i < pom(i)){
            printf("%d ",i);
        }
    }

    return 0;
}
