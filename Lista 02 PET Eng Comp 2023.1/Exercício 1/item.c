#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct Item{ 
    int *data; 
};

VectorItem *vector_item_create(int *data) {
    VectorItem *i = (VectorItem *) malloc ( sizeof(VectorItem));
    if (i == NULL) {
        printf("Problema ao alocar os intens para o vetor\n");
        exit(1);
    }

    i->data = NULL;
    i->data = data;

    return i;
}

void vector_item_print(VectorItem *item) {
    printf("%d", item->data[0]);
}

void vector_item_free(VectorItem *item) {
    free(item);
}