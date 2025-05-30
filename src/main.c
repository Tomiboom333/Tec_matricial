#include "stm32f103xb.h"
#include "tecMat.h"
#include <string.h>
#include "stdbool.h"
char pwi[7]; //password ingresada
char pwc[7]= "CB2008"; //password correcta
char pwn[7]; //password nueva
int ledV = 9, ledR = 10;
int i=0;
int pos=0;
bool correcto=false, hash=false;
int main(void) {
    tecMat_Init (1, 2, 3, 4, 5, 6, 7, 8);

    GPIOA -> CRH &= ~(0xF << (ledV%8)*4);
    GPIOA -> CRH |= (1<<(ledV%8)*4);//pin 9, led verde OUTPUT PUSH-PULL 

    GPIOA -> CRH &= ~(0xF << (ledR%8)*4);
    GPIOA -> CRH |= (1<<(ledR%8)*4);//pin 10, led rojo OUTPUT PUSH-PULL 

    while (1) { 
        char caract = tecMat(1, 2, 3, 4, 5, 6, 7, 8);
        if(caract!='x'){
            if(hash){
                if(pos<6){
                    pwn[pos] = caract;
                    pos++;
                } else if(pos==6){
                    pwn[6]='\0';
                    strcpy(pwc, pwn);
                    memset(pwn, 0, sizeof(pwn));
                    pos=0;
                    hash=false;
                }
            }
            else if(correcto){
                if(caract == '#'){
                    hash = true;
                    correcto=false;
                    i=0;
                }              
            }
            else{
                pwi[i] = caract;
                i++;
                if(i<6){
                    pwi[6]='\0';
                    if (strcmp(pwi, pwc) == 0){
                    GPIOA -> BSRR |= (1<<ledV);
                    GPIOA -> BSRR |= (1<<ledR+16);
                    correcto=true;
                }else{
                    //apagar led y encender rojo 
                    GPIOA -> BSRR |= (1<<ledR);
                    GPIOA -> BSRR |= (1<<ledV+16);
                    correcto=false;
                }
            }
            //borro el string y reseteo posicion
            memset(pwi, 0, sizeof(pwi));
            i=0;
        }

        }
    }
return 0;
}