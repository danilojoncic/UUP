#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

///Ulaz: (jedan[dva][tri][četiri])         Izlaz: ok
///Ulaz: (jedan][dva)                      Izlaz: greska


///kratko receno gledamo slucajeve kada ovaj primjer daje gresku
///zatim trebamo da napravimo nase flagove i promijenljive koje cuvaju trenutne uvitane karaktere
///na kraju IF-ELSE koristimo


int main()
{
    char ch;
    char prva = '\t', druga = '\t';
    while((ch = getchar()) != '\n'){
        if(ch == '(' || ch == '['){
            if(prva == '\t'){
                prva = ch;
           }else{
                druga = ch;
           }
           continue;
        }
        if(ch == ')' || ch == ']'){
            if(prva == '\t'){
                printf("GRESKA");
                return 0;
            }
            if(druga == '\t'){
                if(prva == '(' && ch == ']'){
                    printf("GRESKA");
                    return 0;
                }
                if(prva == '[' && ch == ')'){
                    printf("GRESKA");
                    return 0;
                }

                prva = '\t';
                continue;
            }
            if(druga == '(' && ch == ']'){
                printf("GRESKA");
                return 0;
            }
            if(druga == '[' && ch == ')'){
                printf("GRESKA");
                return 0;
            }
            druga = '\t';
        }
    }

    if(prva == '\t' && druga == '\t'){
        printf("OK");
    }else{
        printf("GRESKA");
    }

    printf("OK");
    return 0;
}
