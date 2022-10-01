#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
UUP-2017-2018-KLK1-G2-Z3
3 (7p). Nacrtati slededu figuru za unetu visinu n (n>2), primeri:

n=8           n=6         n=5        n=4      n=3
abcDEfgh      abCDef      abCde      aBCd     aBc
abCdeFgg      aBcdEe      aBcDd      AbcC     AbB
aBcdefFf      AbcddD      AbccC      AbbB     aAa
AbcdeeeE      AbcccC      aBbBb      aAAa
AbcddddD      aBbbBb      aaAaa
aBccccCc      aaAAaa
abBbbBbb
aaaAAaaa
*/


int min(int a, int b) {
    return (a > b) ? b : a;
}

int main() {
    int i, j;
    int n;
    int x, y, a, b;

    scanf("%d", &n);

    // Pri crtanju dijagonala koristimo dve promenljive koje nam daju početnu poziciju
    // i onda se povecavaju ili smanjuju za onoliko koliko promenljiva i raste.

    // Promnljiva koja definiše pravu od centra i kreće se u levu stranu. Koristimo (n-1)/2 da bi radilo i za parne i za neparne dimenzije.
    x = (n-1) / 2;
    // Promenljiva koja definiše pravu od centra i kreće se u desnu stranu.
    y = n / 2;
    // Promenljiva koja definiše pravu koja se nalazi sa desne strane slike i kreće se u levu stranu.
    a = y + (n - 1);
    // Promenljiva koja definiše pravu koja se nalazi sa leve strane slike i kreće se u desnu stranu.
    b = x - (n - 1);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            // Sl. linija koda nam služi za ispisivanje određeni broj istih slova u redu.
            char c = min('a' + j, 'a' + n - 1 - i);

            // Ako se nalazimo u dijamantu, moramo povećati slovo.
            if (j == x - i || j == y + i || j == b + i || j == a - i) {
                c -= 32;
            }

            putchar(c);
        }
        putchar('\n');
    }


    return 0;
}

