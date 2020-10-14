#ifndef SPBU_2020_C_CYCLICLIST_H
#define SPBU_2020_C_CYCLICLIST_H

#include "list.h"

typedef struct CyclicList CyclicList;

CyclicList* createCyclicList();

bool insertCyclic(ListElement* newElement, int position, CyclicList* cyclicList);
int getSizeCyclic(CyclicList* cyclicList);

void updateCurrentIndex(CyclicList* cyclicList);
void increaseCurrentIndex(int increment, CyclicList* cyclicList);
int getCurrentValue(CyclicList* cyclicList);
bool deleteCurrent(CyclicList* cyclicList);
void freeCyclicList(CyclicList* cyclicList);

#endif //SPBU_2020_C_CYCLICLIST_H
