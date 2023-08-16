#ifndef _MATRIX_H
#define _MATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include "mytools.h"

typedef struct {
    int rows;
    int cols;
    int data[100][100];
} tMatrix;

tMatrix scanMatrix ();

void printMatrix(tMatrix mat);

tMatrix addMatrices(tMatrix mat1, tMatrix mat2);

tMatrix subtractMatrices(tMatrix mat1, tMatrix mat2);

tMatrix multiplyMatrices(tMatrix mat1, tMatrix mat2);

tMatrix scalarMultiply(tMatrix mat, int scalar);

tMatrix transposeMatrix(tMatrix mat);

void initializeMatrix();

#endif