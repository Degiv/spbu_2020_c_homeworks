#include "../../library/commonUtils/arrayOperations.h"
#include <stdio.h>
#include <stdlib.h>

int* getMerged(int* firstArray, int sizeOfFirstArray, int* secondArray, int sizeOfSecondArray)
{
    int* mergedArrays = calloc(sizeOfFirstArray + sizeOfSecondArray, sizeof(int));
    int i = 0;
    int j = 0;

    while (i < sizeOfFirstArray && j < sizeOfSecondArray) {
        if (firstArray[i] > secondArray[j]) {
            mergedArrays[i + j] = firstArray[i];
            ++i;
        } else {
            mergedArrays[i + j] = secondArray[j];
            ++j;
        }
    }

    while (i < sizeOfFirstArray) {
        mergedArrays[i + j] = firstArray[i];
        ++i;
    }

    while (j < sizeOfSecondArray) {
        mergedArrays[i + j] = secondArray[j];
        ++j;
    }

    return mergedArrays;
}

int main()
{
    printf("Enter a size of first sorted array:\n");
    int sizeOfFirstArray = 0;
    scanf("%d", &sizeOfFirstArray);
    int* firstArray = calloc(sizeOfFirstArray, sizeof(int));
    printf("Enter the first sorted array:\n");
    inputArray(firstArray, sizeOfFirstArray);

    printf("Enter a size of second sorted array:\n");
    int sizeOfSecondArray = 0;
    scanf("%d", &sizeOfSecondArray);
    int* secondArray = calloc(sizeOfSecondArray, sizeof(int));
    printf("Enter the second sorted array:\n");
    inputArray(secondArray, sizeOfSecondArray);

    int* mergedArrays = getMerged(firstArray, sizeOfFirstArray, secondArray, sizeOfSecondArray);
    printf("Merged arrays:\n");
    outputArray(mergedArrays, sizeOfFirstArray + sizeOfSecondArray);

    free(firstArray);
    free(secondArray);
    free(mergedArrays);
    return 0;
}
