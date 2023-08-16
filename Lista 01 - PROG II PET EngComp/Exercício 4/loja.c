#include "loja.h"

struct Loja {
    int id, totalVendedores;
    float aluguel, lucro;
    tVendedor *vendedores;
};

tLoja *abrirLoja (tLoja *lojas, int qtdLojas) {
    lojas = (tLoja *) realloc(lojas, qtdLojas * sizeof(tLoja));

    lojas[qtdLojas-1].id = qtdLojas;
    scanf("%f ", &lojas[qtdLojas-1].aluguel);
    lojas[qtdLojas-1].totalVendedores = 0;
    lojas[qtdLojas-1].lucro = 0;
    lojas[qtdLojas-1].vendedores = NULL;

    return lojas;
}

tLoja *contratarVendedor (tLoja *lojas, int qtdLojas) {
    int idLoja, i;


    scanf("%d ", &idLoja);
    for (i = 0; i < qtdLojas; i++) {
        if (lojas[i].id == idLoja) {
            break;
        }
    }

    lojas[i].totalVendedores++;
    lojas[i].vendedores = registrarVendedor(lojas[i].vendedores, lojas[i].totalVendedores);

    return lojas;
}

void registrarVenda (tLoja *lojas, int qtdLojas) {
    char nomeVendedor[20];
    int idLoja;
    float valorVenda;

    scanf("%d %s %f ", &idLoja, nomeVendedor, &valorVenda);

    for (int i = 0; i < qtdLojas; i++) {
        if (lojas[i].id == idLoja) {
            contabilizarVenda(lojas[i].vendedores, lojas[i].totalVendedores, nomeVendedor, valorVenda);
        }
    }
}

void calculaDespesas (tLoja *lojas, int qtdLojas) {
    float totalSalarios, pgtComissao, valorVendido;
    for (int i = 0; i < qtdLojas; i++) {
        totalSalarios = 0;
        pgtComissao = 0;
        valorVendido = 0;

        totalSalarios = salarioVendedores(lojas[i].vendedores, lojas[i].totalVendedores);
        pgtComissao = comissaoVendedores(lojas[i].vendedores, lojas[i].totalVendedores);
        valorVendido = totalVendidoVendedores(lojas[i].vendedores, lojas[i].totalVendedores);

        lojas[i].lucro = valorVendido - (totalSalarios + pgtComissao + lojas[i].aluguel);
    }
}

void relatorioIndividual (tLoja *lojas, int qtdLojas) {
    int idLoja;

    scanf("%d ", &idLoja);

    calculaDespesas(lojas, qtdLojas);
    for (int i = 0; i < qtdLojas; i++) {
        if (idLoja == lojas[i].id) {
            printf("Loja %d: Lucro total:%.2f\n", lojas[i].id, lojas[i].lucro);
            relatorioVendedores(lojas[i].vendedores, lojas[i].totalVendedores);
            break;
        }
    }
}

void relatorioGeral(tLoja *lojas, int qtdLojas) {
    calculaDespesas(lojas, qtdLojas);
    for (int i = 0; i < qtdLojas; i++) {
        printf("Loja %d: Lucro total: R$%.2f\n", lojas[i].id, lojas[i].lucro);
        relatorioVendedores(lojas[i].vendedores, lojas[i].totalVendedores);
    }
}

void liberaMemoriaLojas (tLoja *lojas, int qtdLojas) {
    for (int i = 0; i < qtdLojas; i++) {
        liberaMemoriaVendedores(lojas[i].vendedores, lojas[i].totalVendedores);
    }
    free(lojas);
}