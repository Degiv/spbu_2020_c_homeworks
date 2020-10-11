#include "../../library/commonUtils/heap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool findSeveralMax(int* numbers, int n, int* result)
{
    buildHeap(numbers, n);

    bool isFound = false;
    int i = 0;
    *result = -1;
    while (i < n - 1 && !(isFound)) {
        swap(&numbers[n - 1 - i], &numbers[0]);
        siftDown(numbers, n - i - 1, 0);
        if (numbers[0] == numbers[n - i - 1]) {
            isFound = true;
            *result = numbers[0];
        }
        ++i;
    }

    return isFound;
}

int main()
{
    int n = 0;
    printf("Enter the length of array :\n");
    scanf("%d", &n);

    int* numbers = (int*)malloc(n * sizeof(int));
    printf("Enter the array :\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &numbers[i]);
    }

    int result = 0;
    if (findSeveralMax(numbers, n, &result)) {
        printf("The maximum that is contained more than once is : %d", result);
    } else {
        printf("The maximum that is contained more than once is not found");
    }

    free(numbers);
}
