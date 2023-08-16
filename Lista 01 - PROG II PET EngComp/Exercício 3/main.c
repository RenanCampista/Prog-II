#include "conta.h"

int main () {
    int opcao, qtdClientes = 0;
    tConta *contas = NULL;

    while (1) {
        scanf("%d ", &opcao);

        if (opcao == 0) {
            //LIBERAR MEMORIA
            liberaMemoria(contas, qtdClientes);
            break;
        } else if (opcao == 1) {
            //SAQUE
            saque(contas, qtdClientes);
        } else if (opcao == 2) {
            //DEPOSITO
            deposito(contas, qtdClientes);
        } else if (opcao == 3) {
            //TRANSFERENCIA
            transferencia(contas, qtdClientes);
        } else if (opcao == 4) {
            //ABERTURA DE CONTA
            qtdClientes++;
            contas = cadastrarConta(contas, qtdClientes);
        } else if (opcao == 5) {
            //RELATORIO
            imprimeRelatorio(contas, qtdClientes);
        }
    }

    return 0;
}