#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int prost(int arg){
    int flag = 1;
    for(int i = 2; i <= sqrt(arg);i++){
        if(arg % i == 0){
            flag = 0;
        }
    }
    return flag;
}


int pom(int arg){
    if(prost(arg)){
        return arg;
    }
    int povecaj = 1;
    while(1){
        if(prost(arg-povecaj)){
            return arg-povecaj;
        }
        if(prost(arg+povecaj)){
            return arg+povecaj;
        }
        povecaj++;
    }
    return -1;





}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i = a; i <= b; i++){
        printf("%d ", pom(i));
    }



    return 0;
}
