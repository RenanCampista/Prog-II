#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "pessoas.h"

struct Item{ 
    void *data; 
    ItemType type;
};

VectorItem *vector_item_create(void *data, int type) {
    VectorItem *i = (VectorItem *) malloc ( sizeof(VectorItem));
    if (i == NULL) {
        printf("Problema ao alocar os intens para o vetor\n");
        exit(1);
    }

    i->data = NULL;
    i->data = data;
    i->type = type;

    return i;
}

void vector_item_print(VectorItem *item) {
    if (item->type == EMPREITEIRO)
        print_empreiteiro((Empreiteiro*)item->data);
    else if (item->type == PROFESSOR)
        print_professor((Professor*)item->data);
    else if (item->type == TECADM)
        print_tec_adm((TecAdm*)item->data);
}

void vector_item_free(VectorItem *item) {
    //free(item->data);
    if (item->type == EMPREITEIRO) {
        free_empreiteiro((Empreiteiro*)item->data);
    } else if (item->type == PROFESSOR) {
        free_professor((Professor*)item->data);
    } else if (item->type == TECADM) {
        free_tec_adm((TecAdm*)item->data);
    }
    free(item);
}