#include "finesdef.h"


tCircular scanCircular () {
    tCircular circle;

    printf("\nInforme o raio: ");
    scanf("%f", &circle.ray);
    //cleanBuffer();
    return circle;
}

tRectangular scanRectangular () {
    tRectangular rectangle;

    printf("\nInforme o comprimento e largura: ");
    scanf("%f %f", &rectangle.length, &rectangle.width);
    cleanBuffer();
    return rectangle;
}

tTriangular scanTriangular () {
    tTriangular triangle;

    printf("\nInforme a base e altura: ");
    scanf("%f %f", &triangle.base, &triangle.height);
    cleanBuffer();
    return triangle;
}

float circularArea (tCircular circle) {
    return (PI * pow(circle.ray, 2));
}

float rectangularArea (tRectangular rectangle) {
    return rectangle.length * rectangle.width;
}

float triangleArea (tTriangular triangle) {
    return (triangle.base * triangle.height) / 2;
}

float sqMeterToHectare (float value) {
    return value / 10000;
}

float amountFine (char type, float hectare) {
    if (type == 'C' || type == 'c') {
        return hectare * FINECIRCULAR;
    } else if (type == 'R' || type == 'r') {
        return hectare * FINERECTANGULAR;
    } else {
        return hectare * FINETRIANGULAR;
    }
}

void initializeFinesDef () {
    tCircular circle;
    tRectangular retangle;
    tTriangular triangle;
    char type;
    int lands, i;
    float area, hectare;

    printf("Informe a quantidade de terreno(s) a ser(em) lido(s): ");
    scanf("%d", &lands);
    cleanBuffer();

    for (i = 0; i < lands; i++) {
        printf("\nTipo do terreno: ");
        scanf("%c", &type);
        cleanBuffer();

        if (type == 'C' || type == 'c') {
           circle = scanCircular();
           area = circularArea(circle);
           hectare = sqMeterToHectare(area);
        } else if (type == 'R' || type == 'r') {
            retangle = scanRectangular();
            area = rectangularArea(retangle);
            hectare = sqMeterToHectare(area);
        } else {
            triangle = scanTriangular();
            area = triangleArea(triangle);
            hectare = sqMeterToHectare(area);
        }
        printf("Preco: %.2f\n", amountFine(type, hectare));
    }
}