#include "../../library/commonUtils/list.h"
#include <stdio.h>

int main()
{
    List* newList = createList();
    printf("Empty list created\n");
    ListElement* newListElement = createListElement(1);
    insert(newListElement, getSize(newList), newList);
    printf("Number '1' inserted in the end:\n");
    showList(newList);

    newListElement = createListElement(2);
    insert(newListElement, getSize(newList), newList);
    printf("Number '2' inserted in the end:\n");
    showList(newList);

    newListElement = createListElement(3);
    insert(newListElement, 1, newList);
    printf("Number '3' inserted on 1st position(counting from 0):\n");
    showList(newList);

    newListElement = createListElement(4);
    insert(newListElement, 3, newList);
    printf("Number '4' inserted on 3rd position(counting from 0):\n");
    showList(newList);

    newListElement = createListElement(5);
    insert(newListElement, 0, newList);
    printf("Number '5' inserted in the beginning:\n");
    showList(newList);

    printf("Show value on 3rd position: %d\n", getValue(retrieve(3, newList)));

    printf("Show position of last inserted element(5): %d\n", locate(newListElement, newList));

    deleteByPosition(0, newList);
    printf("First element deleted:\n");
    showList(newList);

    deleteByPosition(getSize(newList) - 1, newList);
    printf("Last element deleted:\n");
    showList(newList);

    deleteByPosition(1, newList);
    printf("Element on 1st position deleted:\n");
    showList(newList);

    freeList(newList);
}
