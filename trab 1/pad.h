#ifndef _PAD_H
#define _PAD_H


typedef struct Pad tPad;

void cria_diretorios (const char* nome_pasta);

tPad *inicializa_pad ();

void cadastrar_paciente (tPad *p);

void realizar_consulta (tPad *p, const char * caminho);

void buscar_paciente (tPad *p, const char * caminho);

void relatorio_final (tPad *p, const char * caminho);

void free_pad (tPad *p);


#endif