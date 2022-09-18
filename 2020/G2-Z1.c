#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


int brojCifara(int arg){
    int res = 0;
    while(arg){
        arg/=10;
        res++;
    }
    return res;
}



int cut(int n, int k){
    //printf("--------------------\n");
    //printf("Org broj %d, pozicija okretanja %d \n",n,k);
    //printf("Prvi dio cut \n");
/// n -> broj, k -> pozicija (1,2,3,4,5...)
    int broj = n;
    int start = k;
    int poz = brojCifara(n) - k ;
    int curr;
    int novBroj = 0;
    while(start){
        curr = broj % 10;
        //printf("curr : %d \n", curr);
        novBroj += curr * pow(10,poz);
        //printf("novi broj %d \n", novBroj);
        poz++;
        broj /= 10;
        start--;
    }
    //printf("STOP \n");
    poz = 0;
    while(broj){

        //printf("Drugi dio cut \n");
        //printf("poz : %d \n", poz);
        curr = broj % 10;
        //printf("curr : %d \n",curr);
        novBroj += curr * pow(10,poz);
        //printf("novi broj %d \n", novBroj);
        poz++;
        //printf("poz : %d \n", poz);
        broj /= 10;
    }
    //printf("novi broj %d \n",novBroj);
    return novBroj;
}


int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i = a; i <= b; i++){
        if(cut(i,3) > cut(i,2)){
            printf("%d ,",i);
        }
    }
    return 0;
}
