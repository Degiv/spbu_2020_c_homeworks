#ifndef SPBU_2020_C_LIST_H
#define SPBU_2020_C_LIST_H

#include <stdbool.h>

typedef struct ListElement ListElement;
typedef struct List List;

ListElement* createListElement();
int getValue(ListElement* listElement);
List* createList();
ListElement* tail(List* list);
ListElement* head(List* list);
bool isEmpty(List* list);
int getSize(List* list);
bool insert(ListElement* newElement, int position, List* list);
void showList(List* list);
ListElement* retrieve(int position, List* list);
int locate(ListElement* elementToFind, List* list);
bool deleteByPosition(int position, List* list);
void freeList(List* list);

#endif //SPBU_2020_C_LIST_H
