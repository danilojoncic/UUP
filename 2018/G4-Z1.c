#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int prost(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
int pom(int n){
    int proizvod = 1;
    for(int i = 2; i < n; i++){
        if(prost(i) && (n % i == 0)){
            proizvod *= i;
        }
    }
    return proizvod;
}

int main() {
    ///Sad se prekrstimo 3 puta i molimo boga da radi!!!
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i = a; i < b; i++){
        if(i == pom(i)){
            printf("%d ",i);
        }
    }

    return 0;
}
