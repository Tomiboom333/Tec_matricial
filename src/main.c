#include "stm32f103xb.h"
#include "tecMat.h"
#include <string.h>
char pwi[7]; //password ingresada
char pwc[7]= "CB2008"; //password correcta
char pwn[7]; //password nueva
int i;
int main(void) {
    tecMat_Init (1, 2, 3, 4, 5, 6, 7, 8);
    while (1) {
        pwi[7]='/0';
        pwc[7]='/0';
        pwn[7]='/0';
        i=0;
        while((tecMat(1, 2, 3, 4, 5, 6, 7, 8) != 'x') | (i<6)){
            pwi[i] = tecMat(1, 2, 3, 4, 5, 6, 7, 8);
            i++;
        }
        if (strcmp(pwi, pwc) == 0){
            while(tecMat(1, 2, 3, 4, 5, 6, 7, 8) != 'x'){
                if (tecMat(1, 2, 3, 4, 5, 6, 7, 8) == '#'){
                    while(i<6){
                        pwn[i] = tecMat(1, 2, 3, 4, 5, 6, 7, 8);
                        i++;
                    }
                    strcpy(pwc, pwn);
                }
            }
        }
        memset(pwi, 0, sizeof(pwi));
        memset(pwn, 0, sizeof(pwn));
    }
return 0;
}