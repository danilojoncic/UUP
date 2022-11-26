#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int male_zagrade = 0;
    int velike_zagrade = 0;
    int broj = 0;
    int zbir = 0;
    char c;
    while((c = getchar()) != '\n') {
        if(c == '(') {
            male_zagrade++;
            continue;
        }

        if(c == '{') {
            velike_zagrade++;
            continue;
        }

        if(c >= '0' && c <= '9') {
            broj = broj * 10 + c - '0';
        }
        else {
            if(male_zagrade != 0 && velike_zagrade != 0) {
                zbir += -3 * broj;
            }
            else if(male_zagrade != 0) {
                zbir += -broj;
            }
            else if(velike_zagrade != 0) {
                zbir += 3 * broj;
            }
            else {
                zbir += broj;
            }

            if(c == ')')
                male_zagrade--;
            if(c == '}')
                velike_zagrade--;

            broj = 0;
        }
    }
    if(male_zagrade != 0 && velike_zagrade != 0) {
        zbir += -3 * broj;
    }
    else if(male_zagrade != 0) {
        zbir += -broj;
    }
    else if(velike_zagrade != 0) {
        zbir += 3 * broj;
    }
    else {
        zbir += broj;
    }
    printf("%d\n", zbir);
    return 0;
}
