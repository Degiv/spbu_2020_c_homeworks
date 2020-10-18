#include "stack.h"
#include "stdio.h"

struct StackElement {
    double value;
    struct StackElement* next;
};

struct Stack {
    struct StackElement* top;
    int size;
};

StackElement* createStackElement(double value)
{
    StackElement* newStackElement = (StackElement*)malloc(sizeof(StackElement));
    newStackElement->value = value;
    newStackElement->next = NULL;
    return newStackElement;
}

Stack* createStack()
{
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->size = 0;
    newStack->top = NULL;
    return newStack;
}

StackElement* top(Stack* stack)
{
    return stack->top;
}

double getValueSE(StackElement* stackElement)
{
    return stackElement->value;
}

void setValueSE(StackElement* stackElement, double value)
{
    stackElement->value = value;
}

int getSizeOfStack(Stack* stack)
{
    return stack->size;
}

bool StackIsEmpty(Stack* stack)
{
    return getSizeOfStack(stack) == 0;
}

void push(StackElement* newElement, Stack* stack)
{
    newElement->next = stack->top;
    stack->top = newElement;
    ++stack->size;
}

StackElement* pop(Stack* stack)
{
    if (StackIsEmpty(stack)) {
        return NULL;
    }
    StackElement* formerTop = stack->top;
    stack->top = stack->top->next;
    --stack->size;
    return formerTop;
}

void freeStack(Stack* stack)
{
    StackElement* elementToFree = pop(stack);
    while (!StackIsEmpty(stack)) {
        free(elementToFree);
        elementToFree = elementToFree->next;
    }
    free(stack);
}

void showStack(Stack* stack)
{
    StackElement* iterator = stack->top;
    while (iterator != NULL) {
        printf("%f", iterator->value);
        iterator = iterator->next;
    }
    printf("\n");
}
