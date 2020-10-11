#ifndef SPBU_2020_C_HEAP_H
#define SPBU_2020_C_HEAP_H

#include <stdbool.h>
#include "numericOperations.h"

void siftUp(int* numbers, int position);

void siftDown(int* numbers, int n, int position);

void buildHeap(int* numbers, int n);

#endif //SPBU_2020_C_HEAP_H