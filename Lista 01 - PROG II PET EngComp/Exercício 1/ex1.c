#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcula_esfera (float R, float* area, float* volume) {
    float pi = 3.14;
    
    *area = 4 * pow(R, 2) * pi;
    *volume = (4 * pow(R, 3) * pi) / 3;
}

int main() {
    float r = 3.8;
    float *area = (float*) calloc(1 , sizeof(float));
    float *volume = (float*) calloc(1, sizeof(float));

    calcula_esfera(r, area, volume);

    printf("\nVolume = %.2f", *volume);
    printf("\nArea = %.2f", *area);

    free(area);
    free(volume);
    return 0;
}