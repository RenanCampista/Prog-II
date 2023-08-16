#ifndef _CONTA_H
#define _CONTA_H
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Conta tConta;

tConta *cadastrarConta (tConta *contas, int qtdClientes);

void imprimeRelatorio (tConta *contas, int qtdClientes);

void saque (tConta *contas, int qtdClientes);

void deposito (tConta *contas, int qtdClientes);

void transferencia (tConta *contas, int qtdClientes);

void liberaMemoria (tConta *contas, int qtdContas);

#endif