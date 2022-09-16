#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int stepen(int a,int b){
    int rezultat = 1;
    if(b > 0){
    while(b){
        rezultat *= a;
        b--;
      }
    }else{
        rezultat = 1;
    }
    return rezultat;
}

int pom(int arg,int k){
    int brojDobijen = 0;
    int brojPredjenih = 0;
    int unos = arg;
    while(unos){
        int trenutnaCifra = unos % 10;
        printf("trenutna cifra %d \n",trenutnaCifra);
        if(trenutnaCifra < k){
            printf("broj dobijen : %d \n",brojDobijen);
            brojDobijen += (trenutnaCifra * stepen(10,brojPredjenih));
            brojPredjenih++;
            unos /= 10;
            printf("broj predjenih %d \n",brojPredjenih);
        }else{

            unos /= 10;
            continue;

        }

    }
    printf("broj dobijen %d \n", brojDobijen);
    printf("\n");


    return brojDobijen;
}


int main()
{   ///MORA DA BUDE MOGUCE!!!
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int zbir = pom(a,6) + pom(b,6) + pom(c,6);
    printf(" zbir : %d ",zbir);


    return 0;
}
