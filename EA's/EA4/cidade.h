#ifndef _CIDADE_H
#define _CIDADE_H

typedef struct Cidade tCidade;


tCidade *criar_cidade ();

void free_cidade (tCidade *c);

void receber_dados (tCidade *c);

void analisar_ataques (tCidade *c);

void imprimir_relatorio (tCidade *c);

void imprimir_relatorio (tCidade *c);

#endif