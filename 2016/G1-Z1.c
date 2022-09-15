#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pom(int arg)   // proslijedjivanje po vrijednosti, zato se arg nece globalno mijenjati
{
    int lijevaCifra,desnaCifra;
    int maxRazlika = 0;

    while(arg > 9){ //provjerava da li je to dvocifren broj
                    //i ako nije ne ulazi u petlju
        desnaCifra = arg % 10;
        arg /= 10;
        lijevaCifra = arg % 10;
        if(abs(lijevaCifra - desnaCifra) > maxRazlika){
            maxRazlika = abs(lijevaCifra - desnaCifra);
        }
    }
    return maxRazlika;
}

int main()
{
    int pocetak,kraj;
    scanf("%d%d",&pocetak,&kraj);
    for(int i = pocetak; i <= kraj;i++){
        if(pom(i) >= 3){
            continue;
        }else{
            printf("%d ",i);
        }
    }


    return 0;
}
