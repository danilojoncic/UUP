#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///Poenta kod ovih zadataka jeste naci vezu izmedju
///nacrtane figure i unosa (n), indexa i , j;

int main()
{
    int n;
    scanf("%d",&n);


    ///Prvi dio zadatka
    int levaGranica;
    int desnaGranica;
    levaGranica = desnaGranica = n / 2;
    char trenutni = 'a';
    if(n % 2 == 0){
        levaGranica--;
    }
    ///


    for(int i = 0; i < n; i++){
        ///ispisujemo kolone za dati red
        for(int j = 0; j < n; j++){
            if(j == levaGranica || j == desnaGranica){
                printf("^");
            }else if(j > levaGranica && j < desnaGranica){
                printf("*");
            }else{
                printf("%c",trenutni);
            }
            ///zavrsili smo sa ispisom trenutnog reda


        }
        printf("\n");

        if(n % 2 == 0 && i == n / 2 - 1){
            continue;
        }

        if(i < n / 2){
            levaGranica--;   ///sluzi za povecavanje dimenzija unutrasnjeg romba kapica
            desnaGranica++;
            trenutni++;
        }else{
            levaGranica++;
            desnaGranica--;
            trenutni--;
        }
    }

    return 0;
}

