#include "matrix.h"


tMatrix scanMatrix () {
    tMatrix mat;
    int i, j;

    printf("\nNumero de linhas da matriz: ");
    scanf("%d", &mat.rows);
    cleanBuffer();

    printf("\nNumero de colunas da matriz: ");
    scanf("%d", &mat.cols);
    cleanBuffer();

    for (i = 0; i < mat.rows; i++) {
        for (j = 0; j < mat.cols; j++) {
            printf("\nValor para lin: %d col: %d: ", i+1, j+1);
            scanf("%d", &mat.data[i][j]);
            cleanBuffer();
        }
    }
    return mat;
}

void printMatrix(tMatrix mat) {
    int i, j;

    for (i = 0; i < mat.rows; i++) {
        for (j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }
}

tMatrix addMatrices(tMatrix mat1, tMatrix mat2) {
    tMatrix res;
    int i, j;

    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        printf("\nErro: as matrizes devem ter o mesmo tamanho para serem somadas.\n");
        exit(1);
    }

    res.rows = mat1.rows;
    res.cols = mat1.cols;

    for (i = 0; i < mat1.rows; i++) {
        for (j = 0; j < mat1.cols; j++) {
            res.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }

    return res;
}

tMatrix subtractMatrices(tMatrix mat1, tMatrix mat2) {
    tMatrix res;
    int i, j;

    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        printf("\nErro: as matrizes devem ter o mesmo tamanho para serem subtraidas.\n");
        exit(1);
    }

    res.rows = mat1.rows;
    res.cols = mat1.cols;

    for (i = 0; i < mat1.rows; i++) {
        for (j = 0; j < mat1.cols; j++) {
            res.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
        }
    }

    return res;
}

tMatrix multiplyMatrices(tMatrix mat1, tMatrix mat2) {
    tMatrix res;
    int i, j, k;

    if (mat1.cols != mat2.rows) {
        printf("\nErro: o número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz para serem multiplicadas.\n");
        exit(1);
    }

    res.rows = mat1.rows;
    res.cols = mat2.cols;

    for (i = 0; i < mat1.rows; i++) {
        for (j = 0; j < mat2.cols; j++) {
            for (k = 0; k < mat1.cols; k++) {
                res.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }
}

tMatrix scalarMultiply(tMatrix mat, int scalar) {
    tMatrix matScalar;
    int i, j;

    matScalar.rows = mat.rows;
    matScalar.cols = mat.cols;

    for (i = 0; i < mat.rows; i++) {
        for (j = 0; j < mat.cols; j++) {
            matScalar.data[i][j] = mat.data[i][j] * scalar;
        }
    }
    
    return matScalar;
}

tMatrix transposeMatrix(tMatrix mat) {
    tMatrix trasnpose;
    int i, j;

    trasnpose.rows = mat.cols;
    trasnpose.cols = mat.rows;

    for (i = 0; i < mat.cols; i++) {
        for (j = 0; j < mat.rows; j++) {
            trasnpose.data[i][j] = mat.data[j][i];
        }
    }
    return trasnpose;
}

void initializeMatrix() {
    int option, rows, cols, scalar;

    while (1) {
        printf("\t\tMENU PRINCIPAL\n");
        printf("1 - Somar duas matrizes\n");
        printf("2 - Subtrair duas matrizes\n");
        printf("3 - Multiplicar duas matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");

        while (1) {
            scanf("%d", &option);

            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6) {
                break;
            }
            printf("\nPor favor, digite uma opcao valida: ");
        }

        if (option == 1) {
            tMatrix mat1, mat2;

            printf("\nMATRIZ 1\n");
            mat1 = scanMatrix();

            printf("\nMATRIZ 2\n");
            mat2 = scanMatrix();

            printf("\nO resultado da soma e:\n");
            printMatrix(addMatrices(mat1, mat2));
        } else if (option == 2) {
            tMatrix mat1, mat2;
            
            printf("\nMATRIZ 1\n");
            mat1 = scanMatrix();

            printf("\nMATRIZ 2\n");
            mat2 = scanMatrix();

            printf("\nO resultado da subtracao e:\n");
            printMatrix(subtractMatrices(mat1, mat2));
        } else if (option == 3) {
            tMatrix mat1, mat2;

            printf("\nMATRIZ 1\n");
            mat1 = scanMatrix();

            printf("\nMATRIZ 2\n");
            mat2 = scanMatrix();

            printf("\nO resultado da multiplicao e:\n");
            printMatrix(multiplyMatrices(mat1, mat2));
        } else if (option == 4) {
            tMatrix mat;
            mat = scanMatrix();
            
            printf("\nDigite o escalar: ");
            scanf("%d", &scalar);
            cleanBuffer();

            printf("\nO resultado sera: \n");
            printMatrix(scalarMultiply(mat, scalar));
        } else if (option == 5) {
            tMatrix mat;
            mat = scanMatrix();

            printf("\nMatriz Transposta\n");
            printMatrix(transposeMatrix(mat));
        } else break;
    }
}