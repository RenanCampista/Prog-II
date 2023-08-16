#ifndef _VECTOR_H
#define _VECTOR_H
#include "item.h"


typedef struct Vector Vector;

Vector *vector_create ();

void vector_add(Vector *v, int *elem);

VectorItem *vector_get(Vector *v, int idx);

int vector_size(Vector *v);

void vector_remove(Vector *v, int idx);

void vector_print(Vector *v);

void vector_destroy(Vector *v);


#endif