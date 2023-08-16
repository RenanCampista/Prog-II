#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidade.h"
#include "ataque.h"
#include "defesa.h"

struct Cidade {
    float x, y;

    tDefesa **defesa;
    tAtaque **missil;

    int num_defesa;
    int num_missil;

    float dano_recebido;
};

tCidade *criar_cidade () {
    tCidade *c = (tCidade *) malloc(sizeof(tCidade));
    if (c == NULL) {
        printf("Problema criar cidade\n");
        exit(1);
    }

    c->defesa = NULL;
    c->missil = NULL;

    c->num_defesa = 0;
    c->num_missil = 0;
    c->dano_recebido = 0;

    return c;
}

void free_cidade (tCidade *c) {
    for (int i = 0; i < c->num_defesa; i++) {
        free_defesa(c->defesa[i]);
    }

    for (int i = 0; i < c->num_missil; i++) {
        free_ataque(c->missil[i]);
    }

    free(c->defesa);
    free(c->missil);
    free(c);
}

void ler_cidade (tCidade *c) {
    scanf("%f %f", &c->x, &c->y);
}

void receber_dados (tCidade *c) {
    char nome[50];

    while (1) {
        scanf("%s ", nome);

        if (nome[0] == 'C') {
            ler_cidade(c);
        } else if (nome[0] == 'D') {
            tDefesa *d = criar_defesa();
            ler_defesa(d, nome);

            c->num_defesa++;
            c->defesa = (tDefesa **) realloc(c->defesa, c->num_defesa * sizeof(tDefesa *));

            c->defesa[c->num_defesa-1] = d;
        } else if (nome[0] == 'M') {
            tAtaque *a = criar_ataque();
            ler_ataque(a, nome);

            c->num_missil++;
            c->missil = (tAtaque **) realloc(c->missil, c->num_missil * sizeof(tAtaque *));

            c->missil[c->num_missil-1] = a;
        } else if (nome[0] == 'F') {
            break;
        }
    }
}

void analisar_ataques (tCidade *c) {
    for (int i = 0; i < c->num_missil; i++) {
        float dano_causado = 0;
        int aux = 0;
        if (verifica_colisao_atq(c->missil[i], c->x, c->y)) {
            for (int j = 0; j < c->num_defesa; j++) {
                float x_def = retornar_x_def(c->defesa[j]);
                float y_def = retornar_y_def(c->defesa[j]);
                float tam_def = retornar_tam_def(c->defesa[j]);

                if (verifica_acertou_def(c->missil[i], x_def, y_def, tam_def) && verifica_qtd_def_disp(c->defesa[j])) {
                    
                    int duas_def = 0;

                    if (j < c->num_defesa -1) {
                    for (int k = j + 1; k < c->num_defesa; k++) {
                        if (verifica_sobrepos(c->defesa[j], c->defesa[k])  && verifica_qtd_def_disp(c->defesa[k])) {
                            
                            float poder_def = retornar_poder_def(c->defesa[j]) + retornar_poder_def(c->defesa[k]); 
                            dano_causado = retornar_dano_causado(c->missil[i], poder_def);

                            reduzir_def(c->defesa[j]);
                            reduzir_def(c->defesa[k]);

                            duas_def = 1;
                            aux = 1;
                            break;
                        }
                    }
                    }
                    
                    
                    
                    
                    if (duas_def == 0) {
                        float poder_def = retornar_poder_def(c->defesa[j]);
                        dano_causado = retornar_dano_causado(c->missil[i], poder_def);
                        reduzir_def(c->defesa[j]);
                        aux = 1;
                    }

                } 
            }
            if (aux == 0)
                dano_causado = retornar_poder_mis(c->missil[i]);
        }

        registrar_dano_missil(c->missil[i], dano_causado);
        c->dano_recebido += dano_causado;
    }
}

float calcular_efetividade (tCidade *c) {
    float dano_potencial = 0;

    for (int i = 0; i < c->num_missil; i++) {
        dano_potencial += retornar_poder_mis(c->missil[i]);
    }

    float efetiv = (dano_potencial - c->dano_recebido);

    efetiv /= dano_potencial;

    return efetiv *100;
}

void imprimir_relatorio (tCidade *c) {
    for (int i = 0; i < c->num_defesa; i++) {
        imprimir_def(c->defesa[i]);
    }

    for (int i = 0; i < c->num_missil; i++) {
        imprimri_missil(c->missil[i]);
    }

    printf("Efetividade: %.2f%%", calcular_efetividade(c));
}