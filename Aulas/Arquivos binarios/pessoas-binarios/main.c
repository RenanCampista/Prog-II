#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main() {
    tPessoa **pessoas = NULL;
    int num_pessoas = 0;
    char opcao;

    while (1) {
        printf("\t\tSELECIONE UMA DAS OPCOES ABAIXO\n\n");
        printf("CADASTRAR UMA PESSOA (C)\n");
        printf("SALVAR DADOS EM UM ARQUIVO BINARIO (S)\n");
        printf("LER UM ARQUIVO BINARIO DE PESSOAS (L)\n");
        printf("ENCERRAR O PROGRAMA (F)\n");
        printf("\n\nOPCAO ESCOLHIDA: ");
        scanf("\n%c", &opcao);

        if (opcao == 'C') {
            system("clear||cls");
            tPessoa *p = criar_pessoa();
            ler_dados_pessoa(p);

            num_pessoas++;
            pessoas = (tPessoa**) realloc(pessoas, num_pessoas * sizeof(tPessoa*));
            pessoas[num_pessoas-1] = p;
            
            printf("PESSOA CADASTRADA COM SUCESSO\n");

        } else if (opcao == 'S') {
            system("clear||cls");
            FILE *file = fopen("pessoas.bin", "wb");

            if (file == NULL) {
                printf("ERRO AO ABRIR O ARQUIVO PARA ESCRITA\n");
                return 1;
            }
            
            for (int i = 0; i < num_pessoas; i++) {
                salvar_dados_pessoa(pessoas[i], file);
            }

            fclose(file);

            file = fopen("total_pessoas.bin", "wb");
            if (file == NULL) {
                printf("ERRO AO ABRIR O ARQUIVO PARA ESCRITA\n");
                return 1;
            }

            fwrite(&num_pessoas, sizeof(int), 1, file);
            fclose(file);

            printf("OS DADOS FORAM SALVOS NO ARQUIVO\n");
        } else if (opcao == 'L') {
            system("clear||cls");
            FILE *file = fopen("total_pessoas.bin", "rb");

            if (file == NULL) {
                printf("ERRO AO ABRIR O ARQUIVO PARA LEITURA\n");
                return 1;
            }

            fread(&num_pessoas, sizeof(int), 1, file);
            fclose(file);

            pessoas = (tPessoa**) realloc(pessoas, num_pessoas * sizeof(tPessoa*));

            file = fopen("pessoas.bin", "rb");
            
            if (file == NULL) {
                printf("ERRO AO ABRIR O ARQUIVO PARA LEITURA\n");
                return 1;
            }

            for (int i = 0; i < num_pessoas; i++) {
                pessoas[i] = criar_pessoa();
                ler_arquivo_pessoa(pessoas[i], file);
            }

            fclose(file);

            printf("DADOS DAS PESSOAS LIDAS:\n");
            for (int i = 0; i < num_pessoas; i++) {
                    imprime_pessoa(pessoas[i]);
            }
        } else if (opcao == 'F') {
            system("clear||cls");
            for (int i = 0; i < num_pessoas; i++) {
                free_pessoa(pessoas[i]);
            }
            free(pessoas);
            break;
        }
    }

    return 0;
}
