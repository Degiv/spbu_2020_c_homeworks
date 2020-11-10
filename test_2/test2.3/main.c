#include <stdio.h>
#define MAX_NUMBER 1000000
#define MIN_NUMBER -1000000

void rewriteFiltered(char nameFrom[], char nameTo[], int min, int max)
{
    FILE* fileF = fopen(nameFrom, "r");
    FILE* fileG = fopen(nameTo, "a");
    int current = 0;
    while (fscanf(fileF, "%d", &current) != EOF) {
        if (current > min && current < max) {
            fprintf(fileG, "%d ", current);
        }
    }
    fclose(fileF);
    fclose(fileG);
}

int main()
{
    int a = 0;
    int b = 0;
    printf("Enter a and b:\n");
    scanf("%d %d", &a, &b);
    char nameFrom[] = "f.txt";
    char nameTo[] = "g.txt";
    rewriteFiltered(nameFrom, nameTo, MIN_NUMBER, a);
    rewriteFiltered(nameFrom, nameTo, a - 1, b + 1);
    rewriteFiltered(nameFrom, nameTo, b, MAX_NUMBER);

    return 0;
}
