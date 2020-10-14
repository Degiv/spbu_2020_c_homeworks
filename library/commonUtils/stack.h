#ifndef SPBU_2020_C_HOMEWORKS_STACK_H
#define SPBU_2020_C_HOMEWORKS_STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct StackElement StackElement;
typedef struct Stack Stack;

StackElement* createStackElement(int value);

Stack* createStack();

StackElement* top(Stack* stack);

int getValueSE(StackElement* stackElement);

void setValueSE(StackElement* stackElement, int value);

int getSizeOfStack(Stack* stack);

bool StackIsEmpty(Stack* stack);

void push(StackElement* newElement, Stack* stack);

StackElement* pop(Stack* stack);

void freeStack(Stack* stack);

#endif //SPBU_2020_C_HOMEWORKS_STACK_H
