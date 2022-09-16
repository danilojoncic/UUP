#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pom(int arg){
    int unos = arg;
    int najmanjaRazlika = arg;
    //printf("broj na pocetku %d \n",arg);
    while(unos > 9){
        int prvi = unos % 10;
       // printf("prva cifra sa desna %d \n",prvi);
        unos /= 10;
        int drugi = unos % 10;
       // printf("druga cifra sa desna %d \n",drugi);
        if(abs(prvi - drugi) < najmanjaRazlika){
            najmanjaRazlika = abs(prvi - drugi);
        }

    }
    //printf("najmanja razlika : %d \n",najmanjaRazlika);
    return najmanjaRazlika;
}



int main()
{   ///MORA DA BUDE MOGUCE!!!
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i = a; i <= b; i++){
        if(pom(i) < 5){
            printf("%d, ",i);
        }
    }

    return 0;
}
