#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "constantes.h"

int main() {
    //TESTE
    tVetor *vetor = criar(5, INT);

    preencher(vetor);

    imprimir_vetor(vetor);

    double d = calcula_op(vetor, 'm');
    printf("Media: %lf\n", d);

    d = calcula_op(vetor, 'v');
    printf("Variancia: %lf\n", d);

    d = calcula_op(vetor, 'd');
    printf("Desvio padrao: %lf\n", d);

    free_vetor(vetor);
    
    return 0;
}