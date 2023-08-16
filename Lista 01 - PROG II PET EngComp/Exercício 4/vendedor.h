#ifndef _VENDEDOR_H
#define _VENDEDOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Vendedor tVendedor;

tVendedor *registrarVendedor (tVendedor *vendedores, int totalVendedores);

void contabilizarVenda (tVendedor *vendedores, int totalVendedores, char nomeVendedor[20], int valor);

float salarioVendedores (tVendedor *vendedores, int totalVendedores);

float comissaoVendedores (tVendedor *vendedores, int totalVendedores);

float totalVendidoVendedores (tVendedor *vendedores, int totalVendedores);

void relatorioVendedores (tVendedor *vendedores, int totalVendedores);

void liberaMemoriaVendedores (tVendedor *vendedores, int totalVendedores);

#endif