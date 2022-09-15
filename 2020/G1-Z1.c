#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Fibonaci niz:
// 1 1 2 3 5 8 13...
//za potrebe zadatka posto nisu nizovi kao struktura podataka korisceni
//onda imamo da su pozicije niza 1,2,3,4,5,6,7,8,9...

int pom(int n){
    int prvi = 1, drugi = 1;
    if(n == 1){
        return 2;
    }
    //drugi = 1, prvi = 1, trenutni = 2
    //drugi = 1, prvi = 2, trenutni = 3
    //drugi = 2, prvi = 3, trenutni = 5
    int trenutni = 0,pozicija = 2; // pozicija je 3, jer nam je potrebno dva broja prije,
    while(n > trenutni){
        trenutni = prvi + drugi;
        drugi = prvi;
        prvi = trenutni;

        //standardna formula za fibonaci brojeve

        pozicija++;

        if(n == trenutni){
            return pozicija;
        }
    }
    return -1;
}

int zbirCifara(int n){
    int zbir = 0,cifra;
    while(n > 0){
        cifra = n % 10;
        zbir += cifra;
        n /= 10;
    }
    return zbir;
}


int main()
{   ///MORA DA BUDE MOGUCE!!!
    int n,m;
    scanf("%d%d",&n,&m);
    int zbir,pozicija;
    for(int i = n; i < m; i++){
        zbir = zbirCifara(i);
        pozicija = pom(zbir);
        if(pozicija > 0){
            printf("%d ", pozicija);
        }
    }

    return 0;
}
