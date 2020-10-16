#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define byteSize 8
#define doubleSize 64
#define numOfBytes 8
#define exponentAddition 1023
#define exponentSize 11
#define mantissaSize 52

int exponention(int number, int exponent)
{
    if (exponent <= 0)
        return 1;
    if (exponent % 2 == 0)
        return exponention(number * number, exponent / 2);
    return number * exponention(number, exponent - 1);
}

int* getBinaryCode(double number)
{
    int* code = calloc(doubleSize, sizeof(int));
    unsigned char* bytes = (unsigned char*)&number;

    for (int i = numOfBytes - 1; i >= 0; --i) {
        int mask = 0x80;
        for (int j = 0; j < byteSize; ++j) {
            if (mask & bytes[i])
                code[(numOfBytes - i - 1) * byteSize + j] = 1;
            else
                code[(numOfBytes - i - 1) * byteSize + j] = 0;
            mask >>= 1;
        }
    }
    return code;
}

int getExponent(int* binaryCode)
{
    int offsetExponent = 0;
    for (int i = 0; i < exponentSize; ++i) {
        offsetExponent += binaryCode[1 + i] * exponention(2.0, (double)(exponentSize - i - 1));
    }
    return offsetExponent - exponentAddition;
}

double getMantissa(int* binaryCode)
{
    double mantissa = 1;
    for (int i = 1; i <= mantissaSize; ++i) {
        mantissa += (double)binaryCode[exponentSize + i] * pow(2, -i);
    }
    return mantissa;
}

void showBinaryCode(int* code)
{
    for (int i = 0; i < doubleSize; ++i) {
        printf("%d", code[i]);
    }
    printf("\n");
}

void printDouble(double number)
{
    if (number == 0) {
        printf("Result: 0");
        return;
    }

    int* binaryCode = getBinaryCode(number);
    int exponent = getExponent(binaryCode);
    double mantissa = getMantissa(binaryCode);
    printf("Result: ");
    if (binaryCode[0] == 0)
        printf("+");
    else
        printf("-");
    printf("%lf*2^(%d)", mantissa, exponent);

    free(binaryCode);
    return;
}

int main()
{
    double number = 0;
    printf("Enter a number:\n");
    scanf("%lf", &number);
    printDouble(number);
    return 0;
}
