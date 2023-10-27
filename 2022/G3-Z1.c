#include <stdio.h>

int prost(int arg){
    for(int i = 2; i < arg;i++){
        if(arg % i == 0){
            return 0;
        }
    }
    return 1;
}

int pom(int a, int b){
    int sredina = (a+b)/2;
    int veciProsti;
    int manjiProsti;
    int manjiUdaljenost = 1;
    int veciUdajelnost = 1;
    if(prost(sredina)) return sredina;
    while(1){
        veciProsti = sredina + veciUdajelnost;
        if(prost(veciProsti)) break;
        veciUdajelnost++;
    }
    while(1){
        manjiProsti = sredina - manjiUdaljenost;
        if(prost(manjiProsti)) break;
        manjiUdaljenost++;
    }
    if(manjiUdaljenost == veciUdajelnost){
        return manjiProsti;
    }else{
        return veciUdajelnost > manjiUdaljenost ? manjiProsti : veciProsti;
    }
}

int main(){

    int a,b;
    int manji = 0;
    int veci = 0;
    scanf("%d%d",&a,&b);
    for(int i = a; i <= b; i++){
        if(prost(i)){
            if(i > pom(a,b)){
                veci++;
            }else if(i < pom(a,b)){
                manji++;
            }
        }

    }
    printf("Veci : %d,\nManji : %d \n",veci,manji);
    return 0;
}



