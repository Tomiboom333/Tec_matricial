#include "stm32f103xb.h"
#include "tec_mat.h"

int main(void) {
    int teclado = 0;
    tec_mac_Init (1, 2, 3, 4, 5, 6, 7, 8);
    while (1) {
        tec_mac(1, 2, 3, 4, 5, 6, 7, 8);
    }
    return 0;
}