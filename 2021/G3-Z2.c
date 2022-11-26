#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int isNum(char ch){
    return (ch >= '0' && ch <= '9')? 1 : 0;
}

int reverse(int arg){
    int unos = arg;
    int result = 0;
    while(unos){
        result = result * 10 + (unos % 10);
        unos /= 10;
    }
    return result;
}
int brojCifara(int arg){
    int unos = arg;
    int count = 0;
    while(unos){
        unos /= 10;
        count++;
    }
    return count;
}


int parneCifre(int arg){
    int revert = reverse(arg);
    int count = 1;
    int result = 0;
    while(revert){
        if(count % 2 == 0){
            result = result * 10 + revert % 10;
        }
        count++;
        revert /= 10;
    }

    return result;
}



int main() {
    char curr;
    int flag = 0;
    int broj = 0;
    int result = 0;
    while((curr = getchar()) != '\n'){
        if(curr == '('){
            if(flag  == 1){
                result += parneCifre(broj);
            }else if(flag == 0 || flag > 1){
                result += reverse(broj);
            }
            flag++;
            broj = 0;
        }else if(curr == ')'){
            if(flag  == 1){
                result += parneCifre(broj);
            }else if(flag == 0 || flag > 1){
                result += reverse(broj);
            }

            flag--;
            broj = 0;
        }else if(curr >= 'a' && curr <= 'z'){
            if(flag == 1){
                result += parneCifre(broj);
            }else if(flag == 0 || flag > 1){
                result += reverse(broj);
            }
            broj = 0;
        }else if(isNum(curr)){
            broj = broj * 10 + curr - '0';
        }
    }
    printf("%d", result);




    return 0;
}
