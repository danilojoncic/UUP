#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

///Ulaz: as<a>prvi<b>drugi</b>treci</a>kraj Izlaz: ok
///Ulaz: as<a>prvi</a>drugi<b>treci</b>kraj Izlaz: ok
///Ulaz: as<a>prvi<b>drugi</a>treci</b> Izlaz: greska
///Ulaz: as<a>prvi<b>drugi</b>kraj Izlaz: greska
///Ulaz: as</a>prvi<a>drugi<b>treci</b> Izlaz: greska


//u ovakvim zadacima potrebno je dosta promijenljivih, vecina njih bice flagovi, ili
// za cuvanje prethodnih i trenutnih vrijednosti u sekvenci
int main()
{
    char ch;
    char prev1 = '\n';
    char prev2 = '\n';
    char prev3 = '\n';

    int flagA = 0;
    int flagB = 0;

    char lastOpened1 = '\n';
    char lastOpened2 = '\n';

    while((ch = getchar() != '\n')){
        if(ch == '>'){
            if(prev2 == '<'){
                if(prev1 == 'a'){
                    flagA++;
                    if(flagA + flagB > 1){
                        lastOpened2 = 'a';
                    }else{
                        lastOpened1 = 'a';
                    }
                }else if(prev1 == 'b'){
                    flagB++;
                    if(flagA + flagB > 1){
                        lastOpened2 = 'b';
                    }else{
                        lastOpened1 = 'a';
                    }
                }
            }else if((prev3 == '<') && (prev2 == '/')){
                if(prev1 == 'a'){
                    if(flagA + flagB > 1){
                        if(lastOpened2 != 'a'){
                            printf("Greska \n");
                            return 0;
                        }
                    }else{
                        if(lastOpened1 != 'a'){
                            printf("Greska \n");
                            return 0;
                        }
                    }
                    flagA--;
                }else if(prev1 == 'b'){
                    if(flagA + flagB > 1){
                        if(lastOpened2 != 'b'){
                            printf("Greska \n");
                            return 0;
                        }
                    }else{
                        if(lastOpened1 != 'b'){
                            printf("Greska \n");
                            return 0;
                        }
                    }
                    flagB--;

                }
            }
        }
        if((flagA < 0) || (flagB < 0) || (flagA > 1) || (flagB > 1)){
            printf("Greska \n");
            return 0;
        }
        prev3 = prev2;
        prev2 = prev1;
        prev1 = ch;
    }
    if(flagA || flagB){
        printf("Greska \n");
    }else{
        printf("OK\n");
    }



    return 0;
}
