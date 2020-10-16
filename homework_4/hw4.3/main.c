#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define byteSize 8
#define numOfBytes 4

int exponention(int number, int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent % 2 == 0)
        return exponention(number * number, exponent / 2);
    return number * exponention(number, exponent - 1);
}

int* getBinary(int number)
{
    int *binary =  calloc(sizeof(int) * byteSize, sizeof(int));
    unsigned char *bytes = (unsigned char*)&number;

    for (int i = numOfBytes - 1; i >= 0; --i)
    {
        int mask = 0x80;
        for (int j = 0; j < byteSize; ++j)
        {
            if (mask & bytes[i])
                binary[(numOfBytes - i - 1) * byteSize + j] = 1;
            else
                binary[(numOfBytes - i - 1) * byteSize + j] = 0;
            mask >>= 1;
        }
    }

    return binary;
}

int* sum(int *a, int *b)
{
    int *sum = calloc(sizeof(int) * numOfBytes, sizeof(int));
    sum[sizeof(int) * byteSize - 1] = 0;
    for (int i = sizeof(int) * byteSize - 1; i >= 0; --i)
    {
        sum[i] += a[i] + b[i];
        if (i != 0)
            sum[i - 1] = sum[i] / 2;
        sum[i] %= 2;
    }

    if (a[0] == 1 && b[0] == 1)
    {
        int i = 0;
        for (i = sizeof(int) * byteSize - 1; sum[i] == 0; --i)
        {
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
    for (int i = 1; i < sizeof(int) * byteSize; ++i)
    {
        if (isNegative)
            binary[i] = (binary[i] + 1) % 2;
        decimal += binary[i] * exponention(2, sizeof(int) * byteSize - i - 1);
    }
    if (isNegative)
        decimal *= -1;
    return decimal;
}

void showBinary(int *binary)
{
    for (int i = 0; i < sizeof(int) * byteSize; ++i) {
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

    int *binaryA = getBinary(a);
    int *binaryB = getBinary(b);
    printf("Binary code of first number is: ");
    showBinary(binaryA);
    printf("Binary code of second number is: ");
    showBinary(binaryB);

    int *binarySum = sum(binaryA, binaryB);
    printf("Binary code of sum: ");
    showBinary(binarySum);

    printf("Sum is: %d", getDecimal(binarySum));

    free(binaryA);
    free(binaryB);
    free(binarySum);
}