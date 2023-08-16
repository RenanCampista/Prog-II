#include "conta.h"

struct Conta {
    int numConta;
    float saldo;
    tUsuario *user;
};


tConta *cadastrarConta (tConta *contas, int qtdClientes) {
    char nome[20], cpf[15];

    contas = (tConta *) realloc (contas, qtdClientes * sizeof(tConta));

    scanf("%s %s %d ", nome, cpf, &contas[qtdClientes-1].numConta);
    contas[qtdClientes-1].user = cadastraUsuario(contas[qtdClientes-1].user, nome, cpf);

    contas[qtdClientes-1].saldo = 0.0;

    return contas;
}

void imprimeRelatorio (tConta *contas, int qtdClientes) {
    printf("===| Imprimindo Relatorio |===\n");
    for (int i = 0; i < qtdClientes; i++) {
        printf("Conta: %d\n", contas[i].numConta);
        printf("Saldo: R$ %.2f\n", contas[i].saldo);
        imprimeUsuario(contas[i].user);
    }
}

void saque (tConta *contas, int qtdClientes) {
    int conta;
    float valor;

    scanf("%d %f", &conta, &valor);
    for (int i = 0; i < qtdClientes; i++) {
        if (conta == contas[i].numConta) {
            if (valor <= contas[i].saldo) {
                contas[i].saldo -= valor;
            } else {
                printf("\nSaldo Insuficiente!\n");
            }
        }
    }
}

void deposito (tConta *contas, int qtdClientes) {
    int conta;
    float valor;

    scanf("%d %f", &conta, &valor);
    for (int i = 0; i < qtdClientes; i++) {
        if (conta == contas[i].numConta) {
            if (valor > 0) {
                contas[i].saldo += valor;
            } 
        }
    }
}

void transferencia (tConta *contas, int qtdClientes) {
    int contaOrigem, contaDestino, org, dst;
    float valor;

    scanf("%d %d %f ", &contaOrigem, &contaDestino, &valor);

    for (org = 0; org < qtdClientes; org++) {
        if (contas[org].numConta == contaOrigem) {
            break;
        }
    }

    for (dst = 0; dst < qtdClientes; dst++) {
        if (contas[dst].numConta == contaDestino) {
            break;
        }
    }

    if (valor <= contas[org].saldo && valor > 0) {
        contas[org].saldo -= valor;
        contas[dst].saldo += valor;
    }
}

void liberaMemoria (tConta *contas, int qtdContas) {
    for (int i = 0; i < qtdContas; i++) {
        liberaMemoriaUser(contas[i].user);
    }
    free(contas);
}