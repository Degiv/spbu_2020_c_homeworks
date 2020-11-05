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

void inputArray(int* numbers, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; ++i) {
        scanf("%d", &numbers[i]);
    }
}

void outputArray(int* numbers, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
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
            string = realloc(string, newSize * (sizeof(char)));
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
