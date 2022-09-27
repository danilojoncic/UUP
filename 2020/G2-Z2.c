#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


///UNOS : 15+48+65>17+38+110
///IZLAZ : NE
/// jer 128 < 165




int main() {
    int broj = 0, rezLevo = 0 ,rezDesno = 0, flag = 1;
    char trenutni,operacija = ' ',znak;

    while((trenutni = getchar()) != '\n'){
        if(trenutni == '+' || trenutni == '-'){
            if(operacija == '+'){
                if(flag){
                    rezLevo += broj;
                }else{
                    rezDesno += broj;
                }
            }else if(operacija == '-'){
                if(flag){
                    rezLevo -= broj;
                }else{
                    rezDesno -= broj;
                }
            }else{
                if(flag){
                    rezLevo = broj;
                }else{
                    rezDesno = broj;
                }
            }
            broj = 0;
            operacija = trenutni;
            }else if(trenutni == '>' || trenutni == '<' || trenutni == '='){
                znak = trenutni;
                flag = 0;
                if(operacija == '+'){
                    rezLevo += broj;
                }else{
                    rezDesno -= broj;
                }
                broj = 0;
                operacija = ' '; ///resetujemo nazad na pocetnu vrijednost
            }
            else{
                broj = broj * 10 + trenutni - '0';
            }
        }
        if(operacija == '+'){
            rezDesno += broj;
        }else{
            rezDesno -= broj;
        }

        if(znak == '>')
        (rezLevo > rezDesno) ? printf("DA\n") : printf("NE\n");
    else if(znak == '<')
        (rezLevo < rezDesno) ? printf("DA\n") : printf("NE\n");
    else if(znak == '=')
        (rezLevo == rezDesno) ? printf("DA\n") : printf("NE\n");







    return 0;
}


