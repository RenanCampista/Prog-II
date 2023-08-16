#ifndef _LOJA_H
#define _LOJA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vendedor.h"


typedef struct Loja tLoja;

tLoja *abrirLoja (tLoja *lojas, int qtdLojas);

tLoja *contratarVendedor (tLoja *lojas, int qtdLojas);

void registrarVenda (tLoja *lojas, int qtdLojas);

void calculaDespesas (tLoja *lojas, int qtdLojas);

void relatorioIndividual (tLoja *lojas, int qtdLojas);

void relatorioGeral(tLoja *lojas, int qtdLojas);

void liberaMemoriaLojas (tLoja *lojas, int qtdLojas);


#endif