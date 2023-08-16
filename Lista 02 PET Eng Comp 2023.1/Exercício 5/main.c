#include <stdio.h>
#include <stdlib.h> 
#include "pessoas.h" 
#include "vector.h" 
 
int calcula_salario(ItemType type) {
    switch (type) {
        case EMPREITEIRO:
            return 6500;
        case PROFESSOR:
            return 13000;
        case TECADM:
            return 19500;
        default:
            return 0;
    }
}
 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso incorreto. Digite: %s <caminho_arquivo.bin>\n", argv[0]);
        return 1;
    }

    char *arquivo = argv[1];

    FILE *file = fopen(arquivo, "rb");
    if (file == NULL) {
        printf("ERRO AO TENTAR ABRIR O ARQUIVO\n");
        return 1;
    }

    Vector *v = vector_create(); 

    int qtd_pessoas;
    fread(&qtd_pessoas, sizeof(int), 1, file);

    for (int i = 0; i < qtd_pessoas; i++) {
        int tam_nome;
        fread(&tam_nome, sizeof(int), 1, file);

        char *nome = (char *) malloc ((tam_nome + 1) * sizeof(char));
        fread(nome, sizeof(char), tam_nome, file);
        nome[tam_nome] = '\0';

        int dia, mes, ano;
        fread(&dia, sizeof(int), 1, file);
        fread(&mes, sizeof(int), 1, file);
        fread(&ano, sizeof(int), 1, file);

        int tam_cpf;
        fread(&tam_cpf, sizeof(int), 1, file);

        char *cpf = (char *) malloc((tam_cpf + 1) * sizeof(char));
        fread(cpf, sizeof(char), tam_cpf, file);
        cpf[tam_cpf] = '\0';

        //SUPOR QUE SEJA EMPRETEIRO
        Empreiteiro *empreiteiro = empreiteiro_criar(nome, dia, mes, ano, cpf, calcula_salario);

        vector_add(v, empreiteiro, EMPREITEIRO); 

        free(nome);
        free(cpf);
    }
    fclose(file);
 
    vector_print(v); 
 
    vector_destroy(v);

    return 0; 
}