#include <stdio.h>
#include <stdlib.h>
#include "item.h"

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
    if (item->type == INT)
        printf("%d", ((int*)item->data)[0]);
    else if (item->type == FLOAT)
        printf("%f", ((float*)item->data)[0]);
    else if (item->type == DOUBLE)
        printf("%lf", ((double*)item->data)[0]);
    else
        printf("%c", ((char*)item->data)[0]);

}

void vector_item_free(VectorItem *item) {
    free(item);
}