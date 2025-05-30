#include "stm32f103xb.h"
#include "tecMat.h"
#include <string.h>
char pwi[7];
char pwc[6]= "CB2008";
char pwn[7];
int i;
int main(void) {
    tecMat_Init (1, 2, 3, 4, 5, 6, 7, 8);
    while (1) {
        i=0;
        while((tecMat(1, 2, 3, 4, 5, 6, 7, 8) != 'x') | (i<6)){
            pwi[i] = tecMat(1, 2, 3, 4, 5, 6, 7, 8);
            i++;
            }
        if (strcmp(pwi, pwc) == 0){
            if (tecMat(1, 2, 3, 4, 5, 6, 7, 8) == '#'){
                while((tecMat(1, 2, 3, 4, 5, 6, 7, 8) != 'x') | (i<6)){
                    pwn[i] = tecMat(1, 2, 3, 4, 5, 6, 7, 8);
                    i++;
                }
                strcpy(pwc, pwn);
            }
        }
    }
return 0;
}