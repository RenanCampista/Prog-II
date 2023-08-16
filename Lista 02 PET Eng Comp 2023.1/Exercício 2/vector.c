#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


struct Vector {
    VectorItem **itens;
    int num_itens;
};


Vector *vector_create () {
    Vector *v = (Vector*) malloc(sizeof(Vector));
    if (v == NULL) {
        printf("Problema ao alocar um vector\n");
        exit(1);
    }

    v->itens = NULL;
    v->num_itens = 0;

    return v;
}

void vector_add(Vector *v, void *elem, int type) {
    v->num_itens++;

    v->itens = (VectorItem **) realloc (v->itens, v->num_itens * sizeof(VectorItem*));

    v->itens[v->num_itens-1] = vector_item_create(elem, type);
    
}

VectorItem *vector_get(Vector *v, int idx) {
    return v->itens[idx];
}

int vector_size(Vector *v) {
    return v->num_itens;
}

void vector_remove(Vector *v, int idx) {
    vector_item_free(v->itens[idx]);
    v->num_itens--;
}

void vector_print(Vector *v) {
    printf("[");
    for (int i = 0; i < v->num_itens; i++) {
        
        vector_item_print(v->itens[i]);
        if (i < v->num_itens - 1)
            printf(",");
        
    }
    printf("]\n");
}

void vector_destroy(Vector *v) {
    for (int i = 0; i < v->num_itens; i++) {
        vector_item_free(v->itens[i]);
    }

    free(v->itens);
    free(v);
}