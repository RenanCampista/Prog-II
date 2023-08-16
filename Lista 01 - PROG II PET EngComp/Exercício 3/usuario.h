#ifndef _USUARIO_H
#define _USUARIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Usuario tUsuario;

tUsuario *cadastraUsuario (tUsuario *user, char nome[20], char cpf[15]);

void imprimeUsuario (tUsuario *user);

void liberaMemoriaUser (tUsuario *user);

#endif