#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

tProduto *criar_produto () {
    tProduto *p = (tProduto *) malloc (sizeof(tProduto));
    if (p == NULL) {
        printf("Problema ao criar produto");
        exit(1);
    }

    p->quantidade = 0;
    p->preco = 0;

    return p;
}

void menu_principal () {
    printf("===== Sistema de Registro de Produtos =====\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Exibir lista de produtos cadastrados\n");
    printf("3 - Salvar lista de produtos em arquivo\n");
    printf("4 - Ler lista de produtos de arquivo\n");
    printf("5 - Sair do programa\n");
    printf("Escolha uma opcao:");
}

void free_produto (tProduto *p) {
    free(p);
}

void cadastrar_produto (tProduto *p) {
    printf("\nNome do produto: ");
    scanf("\n%49[^\n]", p->nome);
    printf("\nPreco do produto: ");
    scanf("\n%f", &p->preco);
    printf("\nQuantidade em estoque: ");
    scanf("\n%d", &p->quantidade);
}

void imprimir_produto (tProduto *p, int id) {
    printf("Produto %d:\n", id);
    printf("Nome: %s\n", p->nome);
    printf("Preco: %.2f\n", p->preco);
    printf("Quantidade em estoque: %d\n\n", p->quantidade);
}

void salvar_lista_produtos (tProduto *p, FILE *file) {
    fwrite(p, sizeof(tProduto), 1, file);
}

void ler_lista_produtos (tProduto *p, FILE *file) {
    fread(p, sizeof(tProduto), 1, file);
}

void iniciar_sistema () {
    tProduto **produtos = NULL;
    int num_produtos = 0;

    int opcao;

    while (1) {
        menu_principal();
        scanf("\n%d", &opcao);

        if (opcao == 1) {
            //system("clear||cls");
            tProduto *p = criar_produto();
            cadastrar_produto(p);

            num_produtos += 1;
            produtos = (tProduto **) realloc(produtos, num_produtos * sizeof(tProduto));
            produtos[num_produtos - 1] = p;

        } else if (opcao == 2) {
            //system("clear||cls");
            for (int i = 0; i < num_produtos; i++) {
                imprimir_produto(produtos[i], i+1);
            }

        } else if (opcao == 3) {
            //system("clear||cls");
            FILE *file = fopen("produtos.bin", "wb");
            if (file == NULL) {
                printf("Problema ao abrir o arquivo para escrita\n");
                exit(1);
            }

            fwrite(&num_produtos, sizeof(int), 1, file);

            for (int i = 0; i < num_produtos; i++) {
                salvar_lista_produtos(produtos[i], file);

            }

            fclose(file);

        } else if (opcao == 4) {
            //system("clear||cls");

            for (int i = 0; i < num_produtos; i++) {
                free_produto(produtos[i]);
            }

            FILE *file = fopen("produtos.bin", "rb");
            if (file == NULL) {
                printf("Problema ao abrir o arquivo para leitura\n");
                exit(1);
            }

            fread(&num_produtos, sizeof(int), 1, file);

            produtos = (tProduto **) realloc(produtos, num_produtos * sizeof(tProduto *));

            for (int i = 0; i < num_produtos; i++) {
                produtos[i] = criar_produto();
                ler_lista_produtos(produtos[i], file);
            }

            fclose(file);

            for (int i = 0; i < num_produtos; i++) {
                imprimir_produto(produtos[i], i+1);
            }


        } else if (opcao == 5) {
            //system("clear||cls");
            printf("Encerrando o programa.");
            for (int i = 0; i < num_produtos; i++) {
                free_produto(produtos[i]);
            }
            free(produtos);
            break;

        } else {
            printf("Por favor, digite uma opcao valida\n");
        }
    }
}
