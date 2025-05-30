#include "stm32f103xb.h"
#include "tecMat.h"
int alerta;
char teclado[4][4]={
    {'1','2','3','A'},
    {'4','5','6','B'},    
    {'7','8','9','C'},
    {'*','0','#','D'}
};

void tecMat_Init(int f1, int f2, int f3, int f4, int c1, int c2, int c3, int c4){

    RCC -> APB2ENR|=RCC_APB2ENR_IOPAEN;

    GPIOA->CRL &= ~(0xF<<(f1* 4));    
    GPIOA->CRL |=  (1 << (f1 * 4));//OUTPUT push pull;0001.

    GPIOA->CRL &= ~(0xF<<(f2* 4));    
    GPIOA->CRL |=  (1 << (f2 * 4));//OUTPUT push pull;0001.

    GPIOA->CRL &= ~(0xF<<(f3* 4));    
    GPIOA->CRL |=  (1 << (f3 * 4));//OUTPUT push pull;0001.

    GPIOA->CRL &= ~(0xF<<(f4* 4));    
    GPIOA->CRL |=  (1 << (f4 * 4));//OUTPUT push pull;0001.

    GPIOA->CRL &= ~(0xF<<(c1* 4));   
    GPIOA->CRL |=  (1 << ((c1* 4)+3));   // Cff = 10 , MODE = 00.(input pull up) */
    GPIOA->BSRR|=(1<<(c1));

    GPIOA->CRL &= ~(0xF<<(c2* 4));   
    GPIOA->CRL |=  (1 << ((c2* 4)+3));   // Cff = 10 , MODE = 00.(input pull up) */
    GPIOA->BSRR|=(1<<(c2));

    GPIOA->CRL &= ~(0xF<<(c3* 4));   
    GPIOA->CRL |=  (1 << ((c3* 4)+3));   // Cff = 10 , MODE = 00.(input pull up) */
    GPIOA->BSRR|=(1<<(c3));

    GPIOA->CRL &= ~(0xF<<(c4* 4));   
    GPIOA->CRL |=  (1 << ((c4* 4)+3));   // Cff = 10 , MODE = 00.(input pull up) */
    GPIOA->BSRR|=(1<<(c4));

    GPIOA->BSRR|=(1<<(f1));
    GPIOA->BSRR|=(1<<(f2));
    GPIOA->BSRR|=(1<<(f3));
    GPIOA->BSRR|=(1<<(f4));
}

char tecMat(int f1, int f2, int f3, int f4, int c1, int c2, int c3, int c4){
    int filas[4]={f1,f2,f3,f4};
    int columnas[4]={c1,c2,c3,c4};

    for(int i=0;i<4;i++){
        GPIOA->BSRR |= (1 << filas[0]) | (1 << filas[1]) | (1 << filas[2]) | (1 << filas[3]);
        GPIOA->BSRR|=(1<<(filas[i] + 16));
        for(int j=0;j<4;j++){
             if ((GPIOA->IDR & (1 << columnas[j])) == 0) {
                return teclado[i][j];
             }
        }
    GPIOA->BSRR |= (1 << filas[i]);
    }
    return 0;
}