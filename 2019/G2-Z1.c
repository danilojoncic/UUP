#include <stdio.h>
#include <stdlib.h>

int brojCifara(int arg){
    int brCifra = 0;
    while(arg){
        brCifra++;
        arg /= 10;
    }
    return brCifra;
}


int invertujBroj(int n){
    int invertovaniBroj = 0;

    while(n){
        invertovaniBroj = invertovaniBroj * 10 + n % 10;
        n/= 10;
    }
    return invertovaniBroj;
}


int sumaSimeticnih(int n){
    int brCifara = brojCifara(n);
    int invertovaniBroj = invertujBroj(n);
    for(int i = 0; i < brCifara / 2 ; i++){    ///brCifara / 2 radi optimizacije
        if(n % 10 + invertovaniBroj % 10 != brCifara){
            return 0;
        }
        n /= 10;
        invertovaniBroj /= 10;
    }
    if((brCifara % 2) && (n % 10 != brCifara)){
            return 0;
    }
    return 1;
}

int main() {
    ///Redzic ovaj zadatak radi tako sto uzme arg
    ///invertuje ga i sabere sve cifre arg-a i invertovanog,
    ///zatim gleda kakav je zbir i koji je odnos
    ///zbira pojedinacnih cifara i ukupnog broja cifara
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i = a; i <= b; i++){
        if(sumaSimeticnih(i)){
            printf("%d , ", i);
        }
    }
    return 0;
}
