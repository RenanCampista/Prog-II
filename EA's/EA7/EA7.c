#include <stdio.h>
#include <stdlib.h>
#include "balcao.h"
/*

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
*/

int main () {
    tBalcao *b = criar_balcao();

    ler_balcao(b);

    //imprimir_balcao(b);

    realiza_movimentos(b);

    free_balcao(b);


    return 0;
}