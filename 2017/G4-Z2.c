#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

///Unos: 34{78}67{56{34}56}{34{456}}    isti kao prosli zadatak samo zamijeniti zagrade sa viticastim zagradama
///Izlaz: 34(78)67(56756)(3415)

///izraz u ugnjezdenoj zagradi zamijenjuje zbirom cifara
///koje se nalaze u toj zagradi, a ostali karakteri se prepisuju
///pretpostavka je da su zagrade pravilno otvorene i zatvorene
///I.E to nas ne zanima, i sve savrseno radi kao i uvijek :(
///malo zbunjujuc primjer unosa i izlaza
///u ugnjezdenoj zagradi, najveca cifra se ispisuje a ostale se skipuju


int main() {
    char c;
	int flag = 0;
	int max = 0;

	while((c = getchar()) != '\n') {
        // Ako je otvorena zagrada povećamo flag.
        if (c == '{')
            flag++;
        // Ako smo 2 puta povećali flag odnosno ako smo došli do druge otvorene zagrade:
        if (flag == 2) {
            // Ako je c cifra nalazimo max.
            if (c >= '0' && c <= '9') {
                if (c-'0' > max)
                    max = c-'0';
            }
            // Ako je zatvorena zagrada ispišemo najveću cifru i smanjimo flag.
            else if (c == '}') {
                printf("%d", max);
                flag--;
            }

            // Prelazimo na sledeću iteraciju jer ne ispisujemo karaktere u duploj vitičastoj zagradi.
            continue;
        }
        // Ako je c zatvorena zagrada, smanjujemo flag.
        else if (c == '}') {
            flag--;
        }

        // Pišemo svaki karakter osim u duploj zagradi (tamo ima continue pa se neće ispisati).
        putchar(c);

	}


    return 0;
}
