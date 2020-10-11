#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_SIZE = 100;

int main()
{
    char* s = (char*)malloc(MAX_SIZE * sizeof(char));
    printf("Enter the string 's1' :\n");
    scanf("%s", s);
    int sSize = strlen(s);

    char* s1 = (char*)malloc(MAX_SIZE * sizeof(char));
    printf("Enter the string 's2' :\n");
    scanf("%s", s1);
    int s1Size = strlen(s1);

    int substringCounter = 0;
    bool areEqual = true;
    int j = 0;
    for (int i = 0; i < (sSize - s1Size + 1); ++i) {
        areEqual = true;
        j = 0;
        while (j < s1Size && areEqual) {
            if (s[i + j] != s1[j])
                areEqual = false;
            ++j;
        }
        if (areEqual)
            ++substringCounter;
    }

    printf("The string 's2' is included in the string 's1' %d times", substringCounter);
    free(s);
    free(s1);
}
