#include <stdio.h>
#include <stdlib.h>
#include "luta.h"
#include "carta.h"


struct Luta {
    int *id;
    int *dif_poder;

    tCarta **cartas;
    int num_cartas;
    int qtd_lutas;
    int cartas_descart;
    int cartas_desempt;
};

tLuta *criar_luta() {
    tLuta *l = (tLuta *) malloc (sizeof(tLuta));
    
    if (l == NULL) {
        printf("Problema ao alocar luta\n");
        exit(1);
    }

    l->id = NULL;
    l->cartas = NULL;
    l->dif_poder = NULL;
    l->num_cartas = 0;
    l->qtd_lutas = 0;
    l->cartas_desempt = 0;
    l->cartas_descart = 0;

    return l;
}


void free_luta (tLuta *l) {
    for (int i = 0; i < l->num_cartas; i++) {
        free_carta(l->cartas[i]);
    }
    if (l->cartas != NULL)
        free(l->cartas);
    if (l->id != NULL)
        free(l->id);
    if (l->dif_poder != NULL)
        free(l->dif_poder);
    free(l);
}

void ler_luta (tLuta *l) {
    l->qtd_lutas++;
    l->id = (int *) realloc(l->id, l->qtd_lutas * sizeof(int));
    scanf("\n%d", &l->id[l->qtd_lutas-1]);
}




void realiza_luta (tLuta *l) {
    int id_c1, id_c2;
    char atributo;

    scanf("\n%d %d %c", &id_c1, &id_c2, &atributo);
    int id_1 = 0, id_2 = 0;
    for (int i = 0; i < l->num_cartas; i++) {
        if (retorna_id_carta(l->cartas[i]) == id_1) {
            id_1 = retorna_id_carta(l->cartas[i]);
        } else if (retorna_id_carta(l->cartas[i]) == id_2) {
            id_2 = retorna_id_carta(l->cartas[i]);
        }
    }
    if (verifica_empate(l->cartas[id_1], l->cartas[id_2], atributo) == 0) {
        desempata_combate(l->cartas[id_1], l->cartas[id_2]);
        l->cartas_desempt++;

        l->dif_poder = (int *) realloc(l->dif_poder, l->qtd_lutas * sizeof(int));
        l->dif_poder[l->qtd_lutas-1] = 0;
        
    } else {
        int dif = realiza_combate(l->cartas[id_1], l->cartas[id_2], atributo);
        l->dif_poder = (int *) realloc(l->dif_poder, l->qtd_lutas * sizeof(int));
        if (dif < 0)
            dif *= -1;
        l->dif_poder[l->qtd_lutas-1] = dif;
    }
}


int retorna_carta_mais_vitoriosa (tLuta *l) {
    int maior = 0;
    int valor = 0;
    int id = 0;

    for (int i = 0; i < l->num_cartas; i++) {
        valor = retorna_num_vitorias(l->cartas[i]);
        if (valor > maior) {
            maior = valor;
            id = i;
        }
    }
    return id;
}

int retorna_luta_maior_dif (tLuta *l) {
    int valor = 0;
    int maior = 0;
    int id = 0;
    if (l->qtd_lutas > 0)
        id = 1;

    for (int i = 1; i < l->qtd_lutas; i++) {
        valor = l->dif_poder[i];
        if (valor > maior) {
            maior = valor;
            id = i;
        }
    }
    return id;
}

void emitir_relatorio (tLuta *l) {
    printf("Quantidade de Cartas: %d\n", l->num_cartas);
    printf("Quantidade de descartadas: %d\n", l->cartas_descart);
    printf("Quantidade de lutas: %d\n", l->qtd_lutas);
    if (l->qtd_lutas > 0)
        printf("Lutas que foram desempatadas: %d\n", l->cartas_desempt);
    int id = 0;
    if (l->num_cartas > 0) {
        id = retorna_carta_mais_vitoriosa(l);
        printf("Carta mais vitoriosa: %s\n", retornar_nome_carta(l->cartas[id]));
    }
    if (l->qtd_lutas > 0) {
        id = retorna_luta_maior_dif(l);
        printf("Luta com Maior Diferença: %d\n", id);
    }
}

void realiza_jogo (tLuta *l) {
    char opcao;

    while (1) {
        scanf("\n%c", &opcao);

        if (opcao == 'C' || opcao == 'c') {
            tCarta *c = criar_carta();
            ler_carta(c);
            if (carta_valida(c) == 0) {
                l->cartas_descart++;
                free(c);
            } else {
                int repetido = 0;
                for (int i = 0; i < l->num_cartas; i++) {
                    if (retorna_id_carta(l->cartas[i]) == retorna_id_carta(c)) {
                        free_carta(l->cartas[i]);
                        l->cartas[i] = c;
                        repetido = 1;
                    }
                }
                if (repetido == 0) {
                    l->num_cartas++;
                    l->cartas = (tCarta **) realloc(l->cartas, l->num_cartas * sizeof(tCarta *));
                    l->cartas[l->num_cartas-1] = c;
                }
            }

        } else if (opcao == 'L' || opcao == 'l') {
            ler_luta(l);
            
            realiza_luta(l);

        } else if (opcao == 'F' || opcao == 'f') {
            emitir_relatorio(l);
            free_luta(l);
            break;
        } else {
            printf("opcao invalida\n");
        }
    }
}