#include <stdio.h>

#define CAMINHO 3

int main() {
    int m, n, i, j;
    int xInicial, yInicial, xFinal, yFinal;
    char prioridade[4];

    scanf("%d %d", &m, &n);
    int matriz[m][n];

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d ", &matriz[i][j]);
        }
    }

    scanf("%d %d", &xInicial, &yInicial);
    scanf("%d %d", &xFinal, &yFinal);
    scanf("%s", prioridade);

    printf("(%d,%d) ", xInicial, yInicial);

    i = 0;
    while (1) {
        if ((xInicial == xFinal && yInicial == yFinal) || i > 4) {
            break;
        }

        if (prioridade[i] == 'C' && matriz[xInicial-1][yInicial] == 0) {
            matriz[xInicial-1][yInicial] = CAMINHO;
            xInicial--;
            printf("(%d,%d) ", xInicial, yInicial);
            i = 0;
        } else if (prioridade[i] == 'B' && matriz[xInicial+1][yInicial] == 0) {
            matriz[xInicial+1][yInicial] = CAMINHO;
            xInicial++;
            printf("(%d,%d) ", xInicial, yInicial);
            i = 0;
        } else if (prioridade[i] == 'E' && matriz[xInicial][yInicial-1] == 0) {
            matriz[xInicial][yInicial-1] = CAMINHO;
            yInicial--;
            printf("(%d,%d) ", xInicial, yInicial);
            i = 0;
        } else if (prioridade[i] == 'D' && matriz[xInicial][yInicial+1] == 0) {
            matriz[xInicial][yInicial+1] = CAMINHO;
            yInicial++;
            printf("(%d,%d) ", xInicial, yInicial);
            i = 0;
        } else {
            i++;
        }
    }

    return 0;
}