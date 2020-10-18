#include "../../library/commonUtils/binaryOperations.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BITS_PER_BYTE 8

int* getSum(int* a, int* b)
{
    int* sum = calloc(sizeof(int) * BITS_PER_BYTE, sizeof(int));
    sum[sizeof(int) * BITS_PER_BYTE - 1] = 0;
    for (int i = sizeof(int) * BITS_PER_BYTE - 1; i >= 0; --i) {
        sum[i] += a[i] + b[i];
        if (i != 0)
            sum[i - 1] = sum[i] / 2;
        sum[i] %= 2;
    }

    if (a[0] == 1 && b[0] == 1) {
        int i = 0;
        for (i = sizeof(int) * BITS_PER_BYTE - 1; sum[i] == 0; --i) {
            sum[i] = 1;
        }
        sum[i] = 0;
    }

    return sum;
}

int getDecimal(int* binary)
{
    int decimal = 0;
    bool isNegative = binary[0];
    int multiplier = 1 << sizeof(int) * BITS_PER_BYTE - 2;
    for (int i = 1; i < sizeof(int) * BITS_PER_BYTE; ++i) {
        if (isNegative)
            binary[i] = (binary[i] + 1) % 2;
        decimal += binary[i] * multiplier;
        multiplier >>= 1;
    }
    if (isNegative)
        decimal *= -1;
    return decimal;
}

void showBinary(int* binary)
{
    for (int i = 0; i < sizeof(int) * BITS_PER_BYTE; ++i) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main()
{
    int a = 0;
    int b = 0;
    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);

    int* binaryA = getBinaryCodeInt(a);
    int* binaryB = getBinaryCodeInt(b);
    printf("Binary code of first number: ");
    showBinary(binaryA);
    printf("Binary code of second number: ");
    showBinary(binaryB);

    int* binarySum = getSum(binaryA, binaryB);
    printf("Binary code of sum: ");
    showBinary(binarySum);

    printf("Sum: %d", getDecimal(binarySum));

    free(binaryA);
    free(binaryB);
    free(binarySum);
}
