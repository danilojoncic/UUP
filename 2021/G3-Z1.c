#include <stdio.h>
#include <stdlib.h>

int kubBroja(int arg){
    return arg*arg*arg;

}

int brojCifara(int arg){
    int unos = arg;
    int broj = 0;
    while(unos){
        broj++;
        unos/=10;
    }
    return broj;
    ///Radi da valja
}



int pom(int arg){

    int srednja_cifra;
    int countDesavanja = brojCifara(arg)/2+1;

    int unos = arg;
    int br1,br2;
    if(brojCifara(arg) % 2 == 0){
        while(countDesavanja-1){
            br1 = unos % 10;
            br2 = (unos / 10) % 10;
            unos /= 10;
            countDesavanja--;
        }
        srednja_cifra = br1 > br2 ? br1 : br2;
        ///ovo radi da valja




    }else{
        //printf("broj sa neparnim ciframa %d\n",arg);

        while(countDesavanja){
            srednja_cifra = unos % 10;
            unos /= 10;
            countDesavanja--;
            ///ovo donekle i radi
        }


    }
    //printf("broj : %d srednja cifra : %d\n",arg,srednja_cifra);
    return srednja_cifra;

}





int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i = a; i <= b; i++){
        if(pom(i) == 0)continue;
        if(i % kubBroja(pom(i))  == 0  ){
            printf("%d\n",i);

        }
    }



    return 0;
}
