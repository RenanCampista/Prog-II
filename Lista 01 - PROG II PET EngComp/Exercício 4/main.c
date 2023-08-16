#include "loja.h"

int main () {
    int opcao, qtdLojas = 0;
    tLoja *lojas = NULL;

    while (1) {
        scanf("%d ", &opcao);

        if (opcao == 0) {
            liberaMemoriaLojas(lojas, qtdLojas);
            break;
        } else if (opcao == 1) {
            qtdLojas++;
            lojas = abrirLoja(lojas, qtdLojas);
        } else if (opcao == 2) {
            lojas = contratarVendedor(lojas, qtdLojas);
        } else if (opcao == 3) {
            registrarVenda(lojas, qtdLojas);
        } else if (opcao == 4) {
            relatorioIndividual(lojas, qtdLojas);
        } else if (opcao == 5) {
            relatorioGeral(lojas, qtdLojas);
        }
    }

    return 0;
}