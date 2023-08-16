#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"

int main () {
    tCidade *c = criar_cidade();

    receber_dados(c);

    analisar_ataques(c);

    imprimir_relatorio(c);

    free_cidade(c);

    return 0;
}