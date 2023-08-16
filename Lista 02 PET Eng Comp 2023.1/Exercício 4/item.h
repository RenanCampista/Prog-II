#ifndef _ITEM_H
#define _ITEM_H

typedef enum {
    EMPREITEIRO = 1,
    PROFESSOR = 2,
    TECADM = 3,
    GRADUACAO = 4,
    MESTRADO = 5,
    DOUTORADO = 6
} ItemType;

typedef struct Item VectorItem;

VectorItem *vector_item_create(void *data, int type);

void vector_item_print(VectorItem *item);

void vector_item_free(VectorItem *item);

#endif