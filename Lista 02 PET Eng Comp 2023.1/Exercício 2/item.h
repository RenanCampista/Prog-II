#ifndef _ITEM_H
#define _ITEM_H

typedef enum{ 
    INT = 0, 
    FLOAT = 1, 
    DOUBLE = 2, 
    CHAR = 3 
} ItemType;

typedef struct Item VectorItem;

VectorItem *vector_item_create(void *data, int type);

void vector_item_print(VectorItem *item);

void vector_item_free(VectorItem *item);


#endif