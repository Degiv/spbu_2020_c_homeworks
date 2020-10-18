#include <stdio.h>
#include <stdlib.h>

#define BITS_PER_BYTE 8
#define EXPONENT_ADDITION 1023
#define EXPONENT_SIZE 11
#define MANTISSA_SIZE 52

int* getBinaryCode(double number)
{
    int* code = calloc(sizeof(double) * BITS_PER_BYTE, sizeof(int));
    unsigned char* bytes = (unsigned char*)&number;

    for (int i = sizeof(double) - 1; i >= 0; --i) {
        int mask = 0x80;
        for (int j = 0; j < BITS_PER_BYTE; ++j) {
            if (mask & bytes[i])
                code[(sizeof(double) - i - 1) * BITS_PER_BYTE + j] = 1;
            else
                code[(sizeof(double) - i - 1) * BITS_PER_BYTE + j] = 0;
            mask >>= 1;
        }
    }
    return code;
}

int getExponent(int* binaryCode)
{
    int offsetExponent = 0;
    unsigned long long multiplier = 1 << EXPONENT_SIZE - 1;
    for (int i = 0; i < EXPONENT_SIZE; ++i) {
        offsetExponent += binaryCode[1 + i] * multiplier;
        multiplier >>= 1;
    }
    return offsetExponent - EXPONENT_ADDITION;
}

double getMantissa(int* binaryCode)
{
    double mantissa = 1;
    unsigned long long divider = (unsigned long long)1 << MANTISSA_SIZE;
    for (int i = MANTISSA_SIZE; i > 0; --i) {
        mantissa += (double)(binaryCode[EXPONENT_SIZE + i]) / (double)divider;
        divider >>= 1;
    }
    return mantissa;
}

void showBinaryCode(int* code)
{
    for (int i = 0; i < sizeof(double) * BITS_PER_BYTE; ++i) {
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
