#include <stdio.h>



/*
 * 1. (6p) Napisati funkciju pom(int arg) koja proverava da li među sumama simetričnih
cifara broja arg postoji suma koja je prost broj. Funkcija pom vraća n-ti prost broj, gde je
broj n jednak najvećoj sumi simetričnih cifara koja je prost broj, ako takva suma ne postoji
onda je broj n jednak broju cifara prosleđenog argumenta.
Ispisati sve brojeve koje korisnik unese tako da su im cifre zarotirane ciklično za k mesta u
desno, gde je k povratna vrednost funkcije pom. Korisnik unosi brojeve sve dok ne unese 0.
Primer :Ulaz : 2543670 14862 14761 246 0
Izlaz : 4367025 14862 61147 462
Pojašnjenje funkcije pom na primeru :
arg = 2543670, razmatramo sledeće sume simetričnih cifara 2+0 = 2, 5+7 = 12, 4+6 = 10 i
broj 3 (jer je središnja cifra broja neparne dužine). Od suma {2, 3, 10, 12} najveća prosta
suma je 3. Dakle, funkcija pom(2543670) vraća treći prost broj što je broj 5, pa cifre
broja 2543670 treba da rotiramo ciklično 5 puta u desno :
2543670 -> 0254367 -> 7025436 -> 6702543 -> 3670254 -> 4367025
 */
int brojCifara(int arg){
    int count = 0;
    while(arg){
        count++;
        arg/=10;
    }
    return count;
}


int obrniBroj(int arg){
    int newNum = 0;
    while(arg){
        newNum = newNum * 10 + (arg % 10);
        arg /= 10;
    }
    return newNum;
}

int jeProst(int arg){
    if(arg == 1 || arg == 0) return 0;
    for(int i = 2; i < arg;i++){
        if(arg % i == 0){
            return 0;
        }
    }
    return 1;
}

int prviSaLijeva(int poslijednji, int brojCifara){
    while(brojCifara){
        poslijednji *= 10;
        brojCifara--;
    }
    return poslijednji;
}

int zarotirajDesno(int arg,int k){
    while(k){
        //uzeo sam poslijednju cifru
        int poslijednjaCifra = arg % 10;
        //sada sam je obrisao, time je broj cifara ovog broja smanjen za 1
        arg /= 10;
        //sada tu poslijednju cifru povecavam da odgovara broju cifara da je uklopim
        arg += prviSaLijeva(poslijednjaCifra, brojCifara(arg));
        k--;
    }
    return arg;
}


int ntiProsti(int n){
    int broj = 1;
    while(1){
        if(jeProst(broj)){
            printf("BROJ : %d\n",broj);
            n--;
        }
        if(n == 0){
            printf("NTI PROSTI BROJ : %d\n",broj);
            return broj;
        }
        broj++;
    }
}

int pom(int arg){
    int maxPrimeSum = -1;
    int brojCifaraPocetni = brojCifara(arg);
    int brojPetlje = brojCifara(arg) / 2;
    int obrnutiBroj = obrniBroj(arg);
    int suma = 0;
    while(brojPetlje){
        suma = (arg % 10) + (obrnutiBroj % 10);
        if(jeProst(suma) && suma > maxPrimeSum){
            maxPrimeSum = suma;
        }
        arg /= 10;
        obrnutiBroj /= 10;
        brojPetlje--;
    }
    arg /= 10;
    obrnutiBroj /= 10;
    if((arg % 10) == (obrnutiBroj % 10)){
        suma = arg % 10;
    }
    if(jeProst(suma) && suma > maxPrimeSum){
        maxPrimeSum = suma;
    }

    if (maxPrimeSum == -1) {
        return ntiProsti(brojCifaraPocetni);
    }
    return ntiProsti(maxPrimeSum);
}


//Primer :Ulaz : 2543670 14862 14761 246 0
//Izlaz :        4367025 14862 61147 462
int main() {
    int unos;
    do{
        scanf("%d",&unos);
        if(unos == 0){
            return 0;
        }
        printf("%d, \n", zarotirajDesno(unos, pom(unos)));
    }while(unos != 0);
    return 0;

}
