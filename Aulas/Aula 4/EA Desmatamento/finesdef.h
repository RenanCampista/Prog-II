#ifndef _FINESDEF_H
#define _FINESDEF_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constants.h"
#include "mytools.h"

typedef struct circular {
    float ray;
} tCircular;

typedef struct rectangular {
    float length, width;
} tRectangular;

typedef struct triangular {
    float base, height;
} tTriangular;

tCircular scanCircular ();

tRectangular scanRectangular ();

tTriangular scanTriangular ();

float circularArea (tCircular circle);

float rectangularArea (tRectangular rectangle);

float triangleArea (tTriangular triangle);

float sqMeterToHectare (float value);

float amountFine (char type, float hectare);

void initializeFinesDef ();


#endif