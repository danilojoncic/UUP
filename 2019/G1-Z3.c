#include <stdio.h>
#include <stdlib.h>
#include <math.h>


///Poenta kod ovih zadataka jeste naci vezu izmedju
///nacrtane figure i unosa (n), indexa i , j;

int main()
{
    int n;
    scanf("%d",&n);
    int maxKolona = n*2;
    if(n % 2 == 1){
        maxKolona--;
    }
    int levaGranica;
    int desnaGranica;
    levaGranica = desnaGranica = n - 1;
    if(n % 2 == 0){
        desnaGranica++;
    }


///Dio za krosnju
    for(int i = 0; i < n; i++){
        for(int j = 0; j < maxKolona; j++){
            if(j >= levaGranica && j <= desnaGranica){
                if(i % 4 == 0 && (j== levaGranica || j == desnaGranica)){
                    printf("%%");
                }else if(i % 4 == 2 && (j == levaGranica || j == desnaGranica)){
                    printf("@");
                }else{
                    printf("*");
                }
            }else{
                printf(" ");
            }
        }
        printf("\n");
        levaGranica--;
        desnaGranica++;
    }
///Dio za stablo
    levaGranica = desnaGranica = n - 1;
    if(n % 2 == 0){
        desnaGranica++;
    }

    for(int i = 0 ; i < n/2; i++){
        for(int j = 0; j < maxKolona; j++){
            if(j == levaGranica || j == desnaGranica){
                printf("|");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }




    return 0;
}

