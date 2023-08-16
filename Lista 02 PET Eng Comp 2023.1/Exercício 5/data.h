#ifndef _DATA_H
#define _DATA_H

typedef struct Data Data;

Data *data_create(int dia, int mes, int ano);

void free_data(Data *d);

#endif