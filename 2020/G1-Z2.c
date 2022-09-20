#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main()
{

    //cc 'ovo JE TesTIRAnje' nb 'Ovo JE testiranje' gggg 'OVO jE TEstiraNJE' sss 'OvO je teSTiraNJE'

    char ch, prev = 0, prvo_slovo = 0;
    //rec_flag
    // = 1 - sva slova mala
    // = 2 - sva slova velika
    // = 3 - prvo slovo veliko, ostala mala
    // = 4 - ispisuje se kako je bilo
    int navodnici_flag = 0, rec_flag = 0, slucaj_cetiri_flag = 0;

    while((ch = getchar()) != '\n'){
        if(ch == '\''){
            if(navodnici_flag == 0)
                navodnici_flag = 1;
            else{
                navodnici_flag = 0;
                rec_flag = 0;
                prvo_slovo = 0;
                slucaj_cetiri_flag = 0;
            }
        }
        else if(navodnici_flag == 1){

            if(prvo_slovo != 0 && prev != prvo_slovo && rec_flag == 0){
                if((prev>='a' && prev<='z') && (ch >= 'A' && ch <='Z')||
                   (prev>='A' && prev<='Z') && (ch >= 'a' && ch <='z'))
                    slucaj_cetiri_flag = 1;
            }
            if(prvo_slovo != 0 && rec_flag == 0 && prev == prvo_slovo){
                if((prvo_slovo>='a' && prvo_slovo<='z') && (ch >= 'A' && ch <='Z'))
                    slucaj_cetiri_flag = 1;
            }

            if(prvo_slovo == 0){
                prvo_slovo = ch;
            }

            else if(ch == ' ' && rec_flag == 0){
                if(slucaj_cetiri_flag == 1)
                    rec_flag = 4;
                else if((prvo_slovo>='a' && prvo_slovo<='z') && (prev >='a' && prev<='z'))
                    rec_flag = 1;
                else if((prvo_slovo>='A' && prvo_slovo<='Z') && (prev >='A' && prev<='Z'))
                    rec_flag = 2;
                else if((prvo_slovo>='A' && prvo_slovo<='Z') && (prev >='a' && prev<='z'))
                    rec_flag = 3;
            }

            else{
                if(rec_flag == 1){
                    if(ch>='A' && ch<= 'Z')
                        ch+= 'a' - 'A';
                }
                else if(rec_flag == 2){
                    if(ch>='a' && ch<='z')
                        ch -= 'a' - 'A';
                }
                else if(rec_flag == 3){
                    if(prev == ' ' && (ch>='a' && ch <='z'))
                        ch-= 'a' - 'A';
                    if(prev != ' ' && (ch >= 'A' && ch <= 'Z'))
                        ch+= 'a' - 'A';
                }
            }
        }


        putchar(ch);
        prev = ch;
    }

    return 0;
}
