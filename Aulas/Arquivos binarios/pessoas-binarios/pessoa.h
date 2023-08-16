#ifndef _PESSOA_H
#define _PESSOA_h

typedef struct Pessoa tPessoa;

tPessoa *criar_pessoa ();

void free_pessoa (tPessoa *p);

void ler_dados_pessoa (tPessoa *p);

void salvar_dados_pessoa (tPessoa *p, FILE *file);

void ler_arquivo_pessoa (tPessoa *p, FILE *file);

void imprime_pessoa (tPessoa *p);

#endif