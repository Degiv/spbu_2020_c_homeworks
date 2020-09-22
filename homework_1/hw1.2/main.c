#include <stdio.h>
#include <malloc.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverseArray(int* numbers, int first, int last) {
    for (int i = 0; i <= (last - first) / 2; ++i) {
        swap(&numbers[first + i], &numbers[last - i]);
    }
}

int main() {
    int m = 0;
    printf("Enter the length of the first part of the array :\n");
    scanf("%d", &m);

    int n = 0;
    printf("Enter the length of the second part of the array :\n");
    scanf("%d", &n);

    int *numbers = (int*)malloc((n + m) * sizeof(int));
    printf("Enter the array : ");
    for (int i = 0; i < n + m; ++i) {
        scanf("%d", &numbers[i]);
    }

    reverseArray(numbers, 0, m - 1);
    reverseArray(numbers, m, n + m - 1);
    reverseArray(numbers, 0, n + m - 1);

    printf("The entered array with swapped parts : ");
    for (int i = 0; i < (n + m); ++i) {
        printf("%d ", numbers[i]);
    }
    free(numbers);
}
