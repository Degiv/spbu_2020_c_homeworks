#include "heap.h"

void siftUp(int* numbers, int position)
{
    while (position != 0 && numbers[position] > numbers[(position - 1) / 2]) {
        swap(&numbers[position], &numbers[(position - 1) / 2]);
        position = (position - 1) / 2;
    }
}

void siftDown(int* numbers, int n, int position)
{
    int next = position * 2 + 1;
    bool isHeap = false;
    while (next < n && !isHeap) {
        if (next + 1 < n && numbers[next] < numbers[next + 1])
            next++;

        if (numbers[next] > numbers[position]) {
            swap(&numbers[next], &numbers[position]);
            position = next;
            next = position * 2 + 1;
        } else {
            isHeap = true;
        }
    }
}

void buildHeap(int* numbers, int n)
{
    for (int i = n / 2; i >= 0; --i) {
        siftDown(numbers, n, i);
    }
}
