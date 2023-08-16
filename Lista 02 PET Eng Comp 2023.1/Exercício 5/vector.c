#ifndef _VECTOR_H
#define _VECTOR_H
#include "item.h"

typedef struct Vector Vector;

Vector *vector_create();
void vector_add(Vector *v, void *elem, int type);
VectorItem *vector_get(Vector *v, int idx);
int vector_size(Vector *v);
void vector_remove(Vector *v, int idx);
void vector_print(Vector *v);
void vector_destroy(Vector *v);

#endif


#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector {
    VectorItem **itens;
    int num_itens;
};

Vector *vector_create() {
    Vector *v = (Vector *)malloc(sizeof(Vector));
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

    v->itens = (VectorItem **)realloc(v->itens, v->num_itens * sizeof(VectorItem *));

    v->itens[v->num_itens - 1] = vector_item_create(elem, type);
}

VectorItem *vector_get(Vector *v, int idx) {
    return v->itens[idx];
}

int vector_size(Vector *v) {
    return v->num_itens;
}

void vector_remove(Vector *v, int idx) {
    vector_item_free(v->itens[idx]);

    for (int i = idx; i < v->num_itens - 1; i++) {
        v->itens[i] = v->itens[i + 1];
    }

    v->num_itens--;
    v->itens = (VectorItem **)realloc(v->itens, v->num_itens * sizeof(VectorItem *));
}

void vector_print(Vector *v) {
    for (int i = 0; i < v->num_itens; i++) {
        vector_item_print(v->itens[i]);
    }
    printf("\n");
}

void vector_destroy(Vector *v) {
    for (int i = 0; i < v->num_itens; i++) {
        vector_item_free(v->itens[i]);
    }

    free(v->itens);
    free(v);
}