#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 1, num, oct = 0;

    printf("\nDigite o numero: ");
    scanf("%d", &num);

    while (num > 0) {
        oct += (num % 8) * i;
        i *= 10;
        num = num / 8;
    }
    
    printf("\n\n%d", oct);
    return 0;
}