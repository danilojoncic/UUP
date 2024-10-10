#include <stdio.h>

/*
 * ) Napisati funkciju pom(int arg) koja za prosleđeni broj vraća njemu najbliži fibonačijev broj.
Ako su dva fibonačijeva broja podjednako blizu prosleđenoj vrednosti, vratiti manji. Primeniti
funkciju pom na sve brojeve iz intervala koji unosi korisnik i ispisati rezultate.
Primer: Ulaz: 8 22
Izlaz:
 8 8 8 13 13 13 13 13 13 13 21 21 21 21 21
 */

int jesteFibonaci(int broj){
    int f1 = 0;
    int f2 = 1;
    int temp;
    while(f2 < broj){
        temp = f2;
        f2 = f1 + f2;
        f1 = temp;
        if(f2 == broj) return 1;
    }
    return 0;
}


int pom(int arg){
    int gornji = arg;
    int donji = arg;

    //while za veci broj
    while(1){
        if(jesteFibonaci(gornji)) break;
        gornji++;
    }

    //while za manji broj
    while(1){
        if(jesteFibonaci(donji)) break;
        donji--;
    }
    if((arg - donji) == (gornji - arg)){
        return donji;
    }
    return ((arg - donji) > (gornji - arg))? gornji : donji;
}



int main(){
    int a, b;
    scanf("%d %d",&a,&b);
    for(int i = a; i <= b; i++){
        printf("%d ", pom(i));
    }
}