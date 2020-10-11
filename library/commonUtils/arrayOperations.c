#include "arrayOperations.h"

void reverseArray(int* numbers, int first, int last)
{
    for (int i = 0; i <= (last - first) / 2; ++i) {
        swap(&numbers[first + i], &numbers[last - i]);
    }
}
