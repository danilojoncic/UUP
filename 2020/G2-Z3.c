#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int n,x;
    scanf("%d %d",&n,&x);
    int dim = 2* x;
    for(int i1 = 0; i1 < n; i1++){
        int dimX = (dim - 1) / 2;
        int dimY = (dim) / 2;
        int dimK = dimX - (dim - 1);
        int dimZ = dimY + (dim - 1);

        for(int i2 = 0; i2 < dim; i2++){
            for(int j1 = 0; j1 < n; j1++){\
                for(int j2 = 0; j2 < dim; j2++){
                    if(j2 == dimX || j2 == dimZ){
                        putchar('/');
                    }else if(j2 == dimY || j2 == dimK){
                        putchar('\\');
                    }else if(j2 > dimX && j2 < dimY && j2 > dimK && j2 < dimZ){
                        putchar('*');
                    }else{
                        putchar('.');
                    }
                }
            }
            putchar('\n');
            dimX--;
            dimY++;
            dimK++;
            dimZ--;
        }
    }

    return 0;
}
