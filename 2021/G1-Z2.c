#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///Ulaz: md({3}g)a(sd5a)sad{(10sda)12}g11
///Izlaz: 583


int jeCifra(char c)
{

    if(c >= '0' && c <= '9')
        return 1;
    return 0;

}

int main() {
    int flagS = 0;
    int flagB = 0;
    int curr_num = 0;
    int sum = 0;

    char inner_flag;
    char c;

    while((c = getchar()) != '\n') {
        if(c == '(') {
            flagS++;
            if(flagB != 0)
                inner_flag = '(';

            continue;
        }

        if(c == '{') {
            flagB++;
            if(flagS != 0)
                inner_flag = '{';

            continue;
        }

        if(c >= '0' && c <= '9') {
            curr_num = curr_num *10 + c - '0';
        }
        else {
            if(flagS != 0 && flagB != 0) {
                if(inner_flag == '{')
                    sum += pow(curr_num, 2) * 2;
                else
                    sum += pow(curr_num * 2, 2);
            }
            else if(flagS != 0) {
                sum += curr_num * 2;
            }
            else if(flagB != 0) {
                sum += pow(curr_num, 2);
            }
            else {
                sum += curr_num;
            }

            if(c == ')')
                flagS--;
            if(c == '}')
                flagB--;

            curr_num = 0;
        }

    }
    sum+=curr_num;
    ///jedna linija pravi toliko bola ako je nema



    printf("%d\n", sum);
    return 0;
}
