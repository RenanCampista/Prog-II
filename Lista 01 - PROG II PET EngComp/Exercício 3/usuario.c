#include "usuario.h"

struct Usuario {
    char *nome, cpf[15];
};

tUsuario *cadastraUsuario (tUsuario *user, char nome[20], char cpf[15]) {
    user = (tUsuario*) malloc(sizeof(tUsuario));

    user->nome = (char *) malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(user->nome, nome);

    strcpy(user->cpf, cpf);

    return user;
}

void imprimeUsuario (tUsuario *user) {
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n\n", user->cpf);
}

void liberaMemoriaUser (tUsuario *user) {
    free(user->nome);
    free(user);
}