#include <stdio.h>


/*
 * 1. (6p) Napisati funkciju pom(int arg, int n) koja za prosleđeni broj i vrednost n vraća zbir prvih
n delilaca tog broja. Ako broj ima manje od n delilaca vratiti zbir svih. Primeniti funkciju pom
za n=3, na sve brojeve iz intervala koji unosi korisnik i ispisati rezultate.
Primer: Ulaz: 12 23
Izlaz: 6 14 10 9 7 18 6 20 7 11 14 24
 */

int pom(int arg,int n){
    int zbir = 0;
    int k = 0;
    for(int i = 1; i <= arg;i++){
        if(arg % i == 0){
            zbir += i;
            k++;
        }
        if(k == n){
            break;
        }
    }
    return zbir;
}



int main() {
    int start, end;
    scanf("%d %d",&start,&end);
    while(start <=   end){
        printf("%d ",pom(start,3));
        start++;
    }
    return 0;
}
