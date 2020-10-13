#include "cyclicList.h"
#include <stdlib.h>

struct CyclicList {
    List* list;
    int currentIndex;
};

CyclicList* createCyclicList()
{
    CyclicList* newCyclicList = malloc(sizeof(CyclicList));
    newCyclicList->list = createList();
    newCyclicList->currentIndex = -1;
    return newCyclicList;
}

bool insertCyclic(ListElement* newElement, int position, CyclicList* cyclicList)
{
    return insert(newElement, position, cyclicList->list);
}

int getSizeCyclic(CyclicList* cyclicList)
{
    return getSize(cyclicList->list);
}

void updateCurrentIndex(CyclicList* cyclicList)
{
    cyclicList->currentIndex = cyclicList->currentIndex % getSize(cyclicList->list);
}

void increaseCurrentIndex(int increment, CyclicList* cyclicList)
{
    cyclicList->currentIndex = (cyclicList->currentIndex + increment) % getSize(cyclicList->list);
}

int getCurrentValue(CyclicList* cyclicList)
{
    return getValue(retrieve(cyclicList->currentIndex, cyclicList->list));
}

bool deleteCurrent(CyclicList* cyclicList)
{
    if (!deleteByPosition(cyclicList->currentIndex, cyclicList->list))
        return false;
    cyclicList->currentIndex--;
    updateCurrentIndex(cyclicList);
    return true;
}

void freeCyclicList(CyclicList* cyclicList)
{
    freeList(cyclicList->list);
    free(cyclicList);
}
