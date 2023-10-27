#include <stdio.h>
#include <d3dvec.inl>

int stepen(int a, int k) {
    int rez = 1;
    while (k) {
        rez *= a;
        k--;
    }
    return rez;
}

int obrniCifru(int arg) {
    int nova = 0;
    while (arg) {
        nova *= 10;
        nova += arg % 10;
        arg /= 10;
    }
    return nova;
}

int brojCifara(int arg) {
    int num = 0;
    while (arg) {
        num++;
        arg /= 10;
    }
    return num;
}

int pom(int arg) {
    int k = brojCifara(arg);
    int obrnutBroj = obrniCifru(arg);
    int zbir = 0;
    int brojac = 1;
    int lokalniBroj = 0;
    while (obrnutBroj) {
        lokalniBroj = obrnutBroj % 10;
        if (brojac % 2 == 1) {
            zbir += lokalniBroj;
        }
        brojac++;
        obrnutBroj /= 10;
    }
    return stepen(zbir, k);
}

int izbaciPojavljivanje(int glavni, int unutrasnji) {
    int res = 0;
    int lokalni = 0;
    while (glavni) {
        int cifraGlavnog = glavni % 10;
        int cifraLokalnog = unutrasnji;

        int pronadjen = 0;
        while (cifraLokalnog) {
            if (cifraLokalnog % 10 == cifraGlavnog) {
                 pronadjen = 1;
                break;
            }
            cifraLokalnog /= 10;
        }
        if (!pronadjen) {
            res = res * 10 + cifraGlavnog;
        }
        glavni /= 10;
    }
    return res;
}

int main() {
    int input = 1;
    while(1){
        scanf("%d", &input);
        if(input == 0) break;
        printf("%d \n", izbaciPojavljivanje(input, pom(input)));
    }
    return 0;
}
