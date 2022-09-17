#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int swap(int arg,int x,int y){
///Bitno je prvo naci cifre koje se nalaze na "kordinatama koje smo dobili"
///pozicije se gledaju sa desna, i pocinju sa 1 .
    int broj = arg;
    int pozicija = 1;
    int brojX,brojY;
    while(broj){
        if(pozicija == x){
            brojX = broj % 10;  ///nalazimo broj na X kordinati;
        }else if(pozicija == y){
            brojY = broj % 10;  ///nalazimo broj na Y kordinati;
        }
        broj /= 10;
        pozicija++;
    }
    pozicija = 1;
    int novBroj = 0, pos = 1;
    while(arg){
        int curr;
        if(pozicija == x){
            curr = brojY;       /// ako je poz = x -> y swap
        }else if(pozicija == y){
            curr = brojX;       /// ako je poz = y -> x swap
        }else{
            curr = arg % 10;
        }

        novBroj += curr * pos;

        pos *= 10;  /// idemo na iducu poziciju novog broja;
        arg /= 10;
        pozicija++;
    }
    return novBroj;
}


int main() {
    ///Sad se prekrstimo 3 puta i molimo boga da radi!!!
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i = a; i <= b; i++){
            if(i > swap(i,1,3)){
                printf("%d ,",i);
        }
    }
    return 0;
}
