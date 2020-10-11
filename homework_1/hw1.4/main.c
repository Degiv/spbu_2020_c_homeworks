#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    printf("Enter the number :\n");
    scanf("%d", &n);

    bool* isChecked = (bool*)malloc(n * sizeof(bool));
    for (int i = 0; i < n; ++i) {
        isChecked[i] = false;
    }

    printf("Primes before entered number are : ");
    for (int i = 2; i < n; ++i) {
        if (!isChecked[i]) {
            printf("%d ", i);
            for (int j = i; j < n; j += i) {
                isChecked[j] = true;
            }
        }
    }
    free(isChecked);
}
