#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

///Unos: 25/5*10*2/25
///Izlaz: 4
///rad aritmetickih operacija sa karakterima

int main()
{
   int res = 0;
   int broj = 0;
   char ch;
   char znak;

   while((ch = getchar()) != '\n'){
        if(ch >= '0' && ch <= '9'){
            broj = broj * 10 + ch - '0';
        }else{
            if(res == 0){
                res += broj;   ///pocetno popunjavanje rezultata
            }else{
                if(znak == '*'){     ///forward track za kasnije uslov
                    res *= broj;
                }else{               ///forward track za kasnije uslov
                    res /= broj;
                }
            }
            if(ch == '*'){
                znak = '*';
            }else{
                znak = '/';
            }
            broj = 0;    /// resetovanje vrijednosti za broj radi ponovnog ucitavanja kasnije
        }
   }

   if(znak == '*'){     ///Radi poslijednjih cifara ovo radim
        res *= broj;
   }else{
        res /= broj;    ///jer ako se ovo ne uradi, poslijednja cifra (100) nece biti ucitana jer se
                        ///nalazi pored terminalne nule
   }


   printf("res : %d",res);


    return 0;
}
