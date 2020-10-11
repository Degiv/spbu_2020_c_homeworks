#include "mysorts.h"
#include <stdlib.h>

void countingSort(int* numbers, int n, int first, int last)
{
    int length = last - first + 1;
    int* counters = calloc(length, sizeof(int));

    for (int i = 0; i < n; ++i) {
        ++counters[numbers[i] - first];
    }

    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (counters[j] == 0) {
            ++j;
        }
        numbers[i] = first + j;
        --counters[j];
    }
    free(counters);
}
