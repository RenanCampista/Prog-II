#include "vendedor.h"

struct Vendedor {
    char *nome;
    float valorVendido, salario, prctComissao;
};

tVendedor *registrarVendedor (tVendedor *vendedores, int totalVendedores) {
    char nome[20];

    vendedores = (tVendedor *) realloc(vendedores, totalVendedores * sizeof(tVendedor));

    scanf("%s %f %f ", nome, &vendedores[totalVendedores-1].salario, &vendedores[totalVendedores-1].prctComissao);
    vendedores[totalVendedores-1].nome = (char *) malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(vendedores[totalVendedores-1].nome, nome);

    vendedores[totalVendedores-1].valorVendido = 0;

    return vendedores;
}

void contabilizarVenda (tVendedor *vendedores, int totalVendedores, char nomeVendedor[20], int valor) {
    for (int j = 0; j < totalVendedores; j++) {
        if (strcmp(vendedores[j].nome, nomeVendedor) == 0) {
            vendedores[j].valorVendido += valor;
        }
    }
}

float salarioVendedores (tVendedor *vendedores, int totalVendedores) {
    float salarios = 0; 

    for (int i = 0; i < totalVendedores; i++) {
        salarios += vendedores[i].salario;
    }
    return salarios;
}

float comissaoVendedores (tVendedor *vendedores, int totalVendedores) {
    float pgtComissao = 0;

    for (int i = 0; i < totalVendedores; i++) {
        pgtComissao += (vendedores[i].prctComissao * vendedores[i].valorVendido);
    }
    return pgtComissao;
}

float totalVendidoVendedores (tVendedor *vendedores, int totalVendedores) {
    float valorVendido = 0;

    for (int i = 0; i < totalVendedores; i++) {
        valorVendido += vendedores[i].valorVendido;
    }
    return valorVendido;
}

void relatorioVendedores (tVendedor *vendedores, int totalVendedores) {
    for (int i = 0; i < totalVendedores; i++) {
        printf("\t%s > Total vendido: R$%.2f\n", vendedores[i].nome, vendedores[i].valorVendido);
        printf("\t\tTotal recebido: R$%.2f\n", vendedores[i].salario + (vendedores[i].prctComissao * vendedores[i].valorVendido));
    }
}

void liberaMemoriaVendedores (tVendedor *vendedores, int totalVendedores) {
    for (int i = 0; i < totalVendedores; i++) {
        free(vendedores[i].nome);
    }
    free(vendedores);
}