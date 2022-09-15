#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int armstrong(int n){
    int brojCifara = 0;
    int temp = n; // sluzi za potrebe cuvanja orginalne vrijednosti od n
    while(temp > 0){
        temp /= 10;
        brojCifara++;
    }
    // n = 153
    //cifra = 3
    //zbir cifara = 0 + 3^3
    // n = 15
    //cifra = 6
    //zbri cifara = 27 + 5^3
    // ...

    temp = n; // vracamo mu vrijednost da bi ponovo radili sa temp
    int cifra, zbirCifara = 0;
    while(temp > 0){
        cifra = temp % 10;
        zbirCifara = zbirCifara + pow(cifra,brojCifara);
        temp /= 10;
    }
    int povratnaVrijednost;
    if(n == zbirCifara){
        povratnaVrijednost = 1;
    }else{
        povratnaVrijednost = 0;
    }
    return povratnaVrijednost;
}

int main()
{
    int n;
    scanf("%d",&n);

    int broj = 0;
    while(n != 0){     // n nam sluzi za broj iteracija while petlje
        if(armstrong(broj) == 1){
            printf("%d ",broj);
            n--;
        }
        broj++;

    }

}
