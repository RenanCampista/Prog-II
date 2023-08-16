#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

struct Pessoa {
    char nome[50], cpf[15], data_nascimento[11];

};

tPessoa *criar_pessoa () {
    tPessoa *p = (tPessoa *) malloc (sizeof(tPessoa));
    if (p == NULL) {
        printf("Problema em alocar uma pessoa\n");
        exit(1);
    }

    return p;
}

void free_pessoa (tPessoa *p) {
    free (p);
}

void ler_dados_pessoa (tPessoa *p) {
    printf("\nNOME COMPLETO: ");
    scanf("\n%49[^\n]", p->nome);

    printf("\nCPF: ");
    scanf("\n%s", p->cpf);

    printf("\nDATA DE NASCIMENTO: ");
    scanf("\n%s", p->data_nascimento);
}

void salvar_dados_pessoa (tPessoa *p, FILE *file) {
    fwrite(p, sizeof(tPessoa), 1, file);
}

void ler_arquivo_pessoa (tPessoa *p, FILE *file) {
    fread(p, sizeof(tPessoa), 1, file);
}

void imprime_pessoa (tPessoa *p) {
    printf("NOME: %s\n", p->nome);
    printf("DATA DE NASCIMENTO: %s\n", p->data_nascimento);
    printf("CPF: %s\n", p->cpf);
}