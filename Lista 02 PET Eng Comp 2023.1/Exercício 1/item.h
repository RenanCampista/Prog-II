#ifndef _ITEM_H
#define _ITEM_H


typedef struct Item VectorItem;

VectorItem *vector_item_create(int *data);

void vector_item_print(VectorItem *item);

void vector_item_free(VectorItem *item);


#endif