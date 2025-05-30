#include "stm32f103xb.h"
#include "tecMat.h"
char pwi[6];
char pwc[6]= "CB2008";
int i=0;
int main(void) {
    tecMat_Init (1, 2, 3, 4, 5, 6, 7, 8);
    while (1) {
        while((tecMat(1, 2, 3, 4, 5, 6, 7, 8) != 'x') | (i<6)){
            pwi[i] = tecMat(1, 2, 3, 4, 5, 6, 7, 8);
            i++;
    }
    }
    return 0;
}