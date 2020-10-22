#include "../../library/commonUtils/binaryOperations.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BITS_PER_BYTE 8

void showBinaryCode(int* binaryCode)
{
    for (int i = 0; i < sizeof(int) * BITS_PER_BYTE; ++i) {
        printf("%d", binaryCode[i]);
    }
    printf("\n");
}

void decrease(int* binaryCode)
{
    int i = sizeof(int) * BITS_PER_BYTE - 1;
    while (i >= 0 && binaryCode[i] == 0) {
        binaryCode[i] = 1;
        --i;
    }
    if (i >= 0) {
        binaryCode[i] = 0;
    }
}

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

    return sum;
}

int getDecimal(int* binaryCode)
{
    int decimal = 0;
    bool isNegative = (binaryCode[0] == 1);
    if (isNegative) {
        decrease(binaryCode);
    }

    int multiplier = 1 << sizeof(int) * BITS_PER_BYTE - 2;
    for (int i = 1; i < sizeof(int) * BITS_PER_BYTE; ++i) {
        if (isNegative)
            binaryCode[i] = (binaryCode[i] + 1) % 2;
        decimal += binaryCode[i] * multiplier;
        multiplier >>= 1;
    }
    if (isNegative)
        decimal *= -1;
    return decimal;
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
    showBinaryCode(binaryA);
    printf("Binary code of second number: ");
    showBinaryCode(binaryB);

    int* binarySum = getSum(binaryA, binaryB);
    printf("Binary code of sum: ");
    showBinaryCode(binarySum);

    printf("Sum: %d", getDecimal(binarySum));

    free(binaryA);
    free(binaryB);
    free(binarySum);
}
