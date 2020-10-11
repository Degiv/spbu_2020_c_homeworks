#include <stdio.h>
#include <stdlib.h>

void showBySpiral(int** numbers, int n)
{
    const int firstIndex = n / 2;
    printf("%d ", numbers[firstIndex][firstIndex]);
    int leftBorder = firstIndex;
    int upBorder = firstIndex - 1;
    int rightBorder = firstIndex;
    int downBorder = firstIndex;
    int i = firstIndex;
    int j = firstIndex - 1;

    while (j >= 0) {
        while (i <= rightBorder) {
            printf("%d ", numbers[j][i]);
            i++;
        }
        rightBorder++;

        while (j <= downBorder) {
            printf("%d ", numbers[j][i]);
            j++;
        }
        downBorder++;

        while (i >= leftBorder) {
            printf("%d ", numbers[j][i]);
            i--;
        }
        leftBorder--;

        while (j >= upBorder) {
            printf("%d ", numbers[j][i]);
            j--;
        }
        upBorder--;
    }
}

int main()
{
    int n = 0;
    printf("Enter n :\n");
    scanf("%d", &n);

    int** numbers = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; ++i) {
        numbers[i] = (int*)calloc(n, sizeof(int));
    }

    printf("Enter n x n array :\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &numbers[i][j]);
        }
    }

    printf("Entered array by spiral : ");
    showBySpiral(numbers, n);

    for (int i = 0; i < n; ++i)
        free(numbers[i]);

    free(numbers);
}
