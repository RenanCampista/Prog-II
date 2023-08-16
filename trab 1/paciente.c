#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "lesao.h"
#include "data.h"
#include "historico.h"
#include "layout.h"


struct Paciente {
    char *nome, cartao_sus[TAM_CARTAO_SUS], telefone[TAM_TELEFONE], *genero;
    tData *data_nascimento;
    int possui_consulta;
};

tPaciente *aloca_paciente() {
    tPaciente *p = (tPaciente *) malloc(sizeof(tPaciente));

    if (p == NULL) {
        printf("FALTA MEMORIA PARA ALOCAR UM NOVO PACIENTE\n");
        exit(1);
    }

    return p;
}

void le_paciente (tPaciente *paciente, char nome_paciente[101], char cartao_sus[TAM_CARTAO_SUS]) {
    char genero[15];
    paciente->data_nascimento = inicializa_data();

    printf("\nDATA DE NASCIMENTO: ");
    le_data(paciente->data_nascimento);

    printf("\nTELEFONE: ");
    scanf("\n%s", paciente->telefone);

    printf("\nGENERO: ");
    scanf("\n%s", genero);

    paciente->nome = (char *) malloc((strlen(nome_paciente) + 1) * sizeof(char));
    strcpy(paciente->nome, nome_paciente);

    strcpy(paciente->cartao_sus, cartao_sus);

    paciente->genero = (char *) malloc((strlen(genero) + 1) * sizeof(char));
    strcpy(paciente->genero, genero);

    paciente->possui_consulta = FALSO;

    string_to_upper(paciente->nome);
    string_to_upper(paciente->genero);
}

char *retorna_cartao_sus_paciente  (tPaciente *paciente) {
    char *cartao = (char *) malloc(TAM_CARTAO_SUS * sizeof(char));
    strcpy (cartao, paciente->cartao_sus);
    return cartao;
}

int verifica_consulta (tPaciente *paciente) {
    if (paciente->possui_consulta == VERDADEIRO)
        return VERDADEIRO;
    return FALSO;
}

int verifica_cartao_sus_paciente (tPaciente *paciente, char cartao[TAM_CARTAO_SUS]) {
    if (strcmp(paciente->cartao_sus, cartao) == 0)
        return VERDADEIRO;
    else return FALSO;
}

void atribui_consulta(tPaciente *paciente) {
    paciente->possui_consulta = VERDADEIRO;
}

void imprime_paciente_arq_busca (tPaciente *paciente, FILE *file) {
    fprintf(file, "NOME: %s\n", paciente->nome);
    imprime_data_arq_busca(paciente->data_nascimento, file);
    fprintf(file, "GENERO: %s\n", paciente->genero);
    fprintf(file, "TELEFONE: %s\n", paciente->telefone);
}

int retorna_idade (tPaciente *paciente) {
    return calcula_idade(paciente->data_nascimento);
}

int identifica_genero (tPaciente *paciente) {
    if (strcmp(paciente->genero, "FEMININO") == 0) 
        return GENERO_FEMININO;
    else if (strcmp(paciente->genero, "MASCULINO") == 0)
        return GENERO_MASCULINO;
    else
        return GENERO_OUTROS; 
}

void free_paciente (tPaciente *paciente) {
    if (paciente->nome != NULL)
        free(paciente->nome);
    if (paciente->genero != NULL)
        free(paciente->genero);
    if (paciente->data_nascimento != NULL)
        free_data(paciente->data_nascimento);
    free(paciente);
}