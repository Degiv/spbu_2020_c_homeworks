#ifndef SPBU_2020_C_HOMEWORKS_STACK_H
#define SPBU_2020_C_HOMEWORKS_STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct StackElement StackElement;
typedef struct Stack Stack;

StackElement* createStackElement(double value);

Stack* createStack();

StackElement* top(Stack* stack);

double getValueSE(StackElement* stackElement);

void setValueSE(StackElement* stackElement, double value);

int getSizeOfStack(Stack* stack);

bool StackIsEmpty(Stack* stack);

void push(StackElement* newElement, Stack* stack);

StackElement* pop(Stack* stack);

void freeStack(Stack* stack);

void showStack(Stack* stack);

#endif //SPBU_2020_C_HOMEWORKS_STACK_H
