#include <stdio.h>

void LeOrdenaLista (int lista[], int qtd) {
    int i = 0, j = 0, aux = 0;

    for (i = 0; i < qtd; i++) {
        scanf("%d ", &lista[i]);
    }

    for (i = 0; i < qtd - 1; i++) {
        aux = lista[i];
        for (j = i + 1; j < qtd; j++) {
            if (lista[i] > lista[j]) {
                lista[i] = lista[j];
                lista[j] = aux;
                aux = lista[i];
            }
        }
    }
}

void IdentificaLivro (int lista[], int qtd) {
    int i = 0, j = 0, aux = 0;

    for (i = 0; i < qtd; i++) {
        aux = 0;
        for (j = i + 1; j < qtd; j++) {
            if (lista[i] == lista[j] && lista[j] != -1) {
                lista[j] = -1;
                aux++;
            } 
        }
        if (aux != 0) {
            lista[i] = -1;
        } else if (lista[i] != -1) printf("%d ", lista[i]);
    }
}

int main() {
    int qtd = 0;

    scanf("%d", &qtd);
    int lista[qtd];

    LeOrdenaLista(lista, qtd);
    IdentificaLivro(lista, qtd);

    return 0;
}