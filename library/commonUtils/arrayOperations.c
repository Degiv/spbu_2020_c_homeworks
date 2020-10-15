#include "arrayOperations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseArray(int* numbers, int first, int last)
{
    for (int i = 0; i <= (last - first) / 2; ++i) {
        swap(&numbers[first + i], &numbers[last - i]);
    }
}

char* createString()
{
    int size = 1;
    char* string = calloc(size, sizeof(char));
    int currentIndex = 0;

    char currentSymbol = getchar();
    while (currentSymbol != '\n') {
        if (currentIndex > size - 2) {
            int newSize = size * 2;
            realloc(string, newSize * (sizeof(char)));
            memset(&string[size], ' ', size * (sizeof(char)));
            size = newSize;
        }

        string[currentIndex] = currentSymbol;

        ++currentIndex;
        currentSymbol = getchar();
    }
    string[currentIndex] = '\0';
    return string;
}
