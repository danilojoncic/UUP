#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

///Unos: 34(78)67(56(34)56)(34(456))
///Izlaz: 34(78)67(56756)(3415)

///izraz u ugnjezdenoj zagradi zamijenjuje zbirom cifara
///koje se nalaze u toj zagradi, a ostali karakteri se prepisuju
///pretpostavka je da su zagrade pravilno otvorene i zatvorene
///I.E to nas ne zanima, i sve savrseno radi kao i uvijek :(
///malo zbunjujuc primjer unosa i izlaza


int main()
{

    //34(78)67(56 (34)-> 7    56(34 (456-> 15)  )

    char ch;
    int broj = 0;
    int Flag = 0;




    while((ch = getchar()) != '\n'){
     if(ch == '('){
            Flag++;
        }
        if(Flag < 2){                  ///jedini uslov kada cemo ispisvati
            putchar(ch);
        }
        if(Flag == 2){
            if(ch >= '0' && ch <= '9'){
                broj += ch - '0';
            }
            if(ch == ')'){
                printf("%d",broj);      ///uslov kada cemo stampati
                broj = 0;               ///resetovanje vrijednosti broja za iduce iteracije
            }
        }

        if(ch == ')'){
            Flag--;

        }

    }

    return 0;
}
