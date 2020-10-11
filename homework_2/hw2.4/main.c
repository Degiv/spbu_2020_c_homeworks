#include "../../library/commonUtils/mysorts.h"
#include "../../library/commonUtils/numericOperations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showNumerals(int* numerals, int n)
{
    int i = 0;
    while (numerals[i] == 0) {
        ++i;
    }
    swap(&numerals[i], &numerals[0]);

    i = 0;
    while (i < n) {
        printf("%d", numerals[i]);
        ++i;
    }
}

void inputNumerals(int* numerals, int n)
{
    char* number = (char*)calloc(n + 1, sizeof(char));
    scanf("%s", number);
    for (int i = n - 1; i >= 0; --i) {
        numerals[i] = (int)(number[i] - '0');
    }
    free(number);
}

int main()
{
    int n = 0;
    printf("Enter the length of number :\n");
    scanf("%d", &n);

    printf("Enter the number :\n");
    int* numerals = calloc(n, sizeof(int));

    inputNumerals(numerals, n);
    countingSort(numerals, n, 0, 9);
    showNumerals(numerals, n);

    free(numerals);
    return 0;
}
