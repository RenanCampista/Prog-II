#include <stdio.h>

int main() {
    int num, i = 1, bin = 0;

    printf("Digite o numero: ");
    scanf("%d", &num);

    while (num > 0) {
        bin += (num % 2) * i;
        num = num / 2;
        i *= 10;
    }

    printf("\n\n%d", bin);

    return 0;
}