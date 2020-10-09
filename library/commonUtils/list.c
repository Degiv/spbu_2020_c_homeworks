#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct ListElement {
    int value;
    struct ListElement* next;
    struct ListElement* prev;
};

struct List {
    ListElement* head;
    ListElement* tail;
    int size;
};

List* createList()
{
    List* newList = calloc(1, sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

ListElement* createListElement(int newValue)
{
    ListElement* newListElement = calloc(1, sizeof(ListElement));
    newListElement->prev = NULL;
    newListElement->next = NULL;
    newListElement->value = newValue;
    return newListElement;
}

int getValue(ListElement* listElement)
{
    return listElement->value;
}

ListElement* tail(List* list)
{
    return list->tail;
}

ListElement* head(List* list)
{
    return list->head;
}

bool isEmpty(List* list)
{
    return list->size == 0;
}

int getSize(List* list)
{
    return list->size;
}

bool insert(ListElement* value, int position, List* list)
{
    if (position > getSize(list)) {
        return false;
    }

    if (isEmpty(list)) {
        value->next = NULL;
        value->prev = NULL;
        list->tail = value;
        list->head = value;
        ++list->size;
        return true;
    }

    if (position == 0) {
        head(list)->prev = value;
        value->next = head(list);
        list->head = value;
        if (getSize(list) == 1)
            list->tail = value->next;
        ++list->size;
        return true;
    }

    if (position == getSize(list)) {
        tail(list)->next = value;
        value->prev = tail(list);
        list->tail = value;
        ++list->size;
        return true;
    }

    ListElement* iterator = head(list);
    for (int i = 0; i < position; ++i) {
        iterator = iterator->next;
    }
    iterator->prev->next = value;
    value->prev = iterator->prev;
    iterator->prev = value;
    value->next = iterator;
    ++list->size;
    return true;
}

void showList(List* list)
{
    ListElement* iterator = list->head;
    for (int i = 0; i < getSize(list); ++i) {
        printf("%d ", iterator->value);
        iterator = iterator->next;
    }
    printf("\n");
}

ListElement* retrieve(int position, List* list)
{
    ListElement* iterator = head(list);
    for (int i = 0; i < position; ++i) {
        iterator = iterator->next;
    }
    return iterator;
}

int locate(ListElement* value, List* list)
{
    ListElement* iterator = head(list);
    int index = 0;
    while (iterator != 0 && iterator != value) {
        iterator = iterator->next;
        ++index;
    }
    if (index == getSize(list)) {
        return -1;
    }
    return index;
}

bool deleteByPosition(int position, List* list)
{
    if (position >= getSize(list) || position < 0) {
        return false;
    }

    if (getSize(list) == 1) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        --list->size;
        return true;
    }

    if (position == 0) {
        head(list)->next->prev = NULL;
        ListElement* tmp = head(list);
        list->head = head(list)->next;
        free(tmp);
        --list->size;
        return true;
    }

    if (position == getSize(list) - 1) {
        tail(list)->prev->next = NULL;
        ListElement* tmp = tail(list);
        list->tail = tail(list)->prev;
        free(tmp);
        --list->size;
        return true;
    }

    ListElement* iterator = head(list);
    for (int i = 0; i < position; ++i) {
        iterator = iterator->next;
    }
    iterator->prev->next = iterator->next;
    iterator->next->prev = iterator->prev;
    free(iterator);
    --list->size;
    return true;
}

void freeList(List* list)
{
    while (!isEmpty(list)) {
        deleteByPosition(0, list);
    }
    free(list);
}