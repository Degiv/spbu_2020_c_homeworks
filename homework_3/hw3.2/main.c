#include "../../library/commonUtils/cyclicList.h"
#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter n:\n");
    scanf("%d", &n);

    int m = 0;
    printf("Enter m:\n");
    scanf("%d", &m);

    CyclicList* warriors = createCyclicList();
    ListElement* newWarrior = NULL;
    for (int i = 0; i < n; ++i) {
        newWarrior = createListElement(i + 1);
        insertCyclic(newWarrior, getSizeCyclic(warriors), warriors);
    }

    while (getSizeCyclic(warriors) > 1) {
        increaseCurrentIndex(m, warriors);
        deleteCurrent(warriors);
    }

    printf("Your position should be: %d\n", getCurrentValue(warriors));
    freeCyclicList(warriors);
}
