#include <stdio.h>
#include <stdlib.h>


int jesiKvadrat(int arg){
    int flag = 0;
    for(int i = 0; i <= arg;i++){
        if((i*i) == arg){
            flag = 1;
        }
    }
    //printf("arg = %d \n",arg);
    return flag;
    ///Ovo valja i tacno je!!!

}


int pom(int arg){
    if(jesiKvadrat(arg)){
        return arg;
        ///prvi slucaj uspjesno radi
    }
    int povecanje = 1;
    while(1){
        if(jesiKvadrat(arg+povecanje)){
            return arg+povecanje;
        }
        if(jesiKvadrat(arg-povecanje)){
            return arg-povecanje;
        ///maltene radi skroz dobro, nego me brine ovaj uslov ako je broj podjednako...
        }
        jesiKvadrat(arg+povecanje) > jesiKvadrat(arg-povecanje)? arg+povecanje : arg - povecanje;


        povecanje++;

    }







}



int main()
{





    int a,b;
    scanf("%d%d",&a,&b);
    for(int i = a; i <= b; i++){
        printf("%d ",pom(i));
    }

    return 0;
}
