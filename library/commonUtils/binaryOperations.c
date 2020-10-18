#include "binaryOperations.h"
#include <stdio.h>
#include <stdlib.h>

#define BITS_PER_BYTE 8

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

int* getBinaryCodeInt(int number)
{
    int* binary = calloc(sizeof(int) * BITS_PER_BYTE, sizeof(int));
    unsigned char* bytes = (unsigned char*)&number;

    for (int i = sizeof(int) - 1; i >= 0; --i) {
        int mask = 0x80;
        for (int j = 0; j < BITS_PER_BYTE; ++j) {
            if (mask & bytes[i])
                binary[(sizeof(int) - i - 1) * BITS_PER_BYTE + j] = 1;
            else
                binary[(sizeof(int) - i - 1) * BITS_PER_BYTE + j] = 0;
            mask >>= 1;
        }
    }

    return binary;
}
