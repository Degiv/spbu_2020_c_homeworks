#include "stack.h"

typedef struct StackElement
{
    char value;
    struct StackElement* next;
} StackElement;

typedef struct Stack
{
    struct StackElement* top;
    int size;
} Stack;

StackElement* createStackElement(char value)
{
    StackElement* newStackElement = (StackElement*)calloc(1, sizeof(StackElement));
    newStackElement->value = value;
    newStackElement->next = NULL;
}

Stack* createStack()
{
    Stack* newStack = (Stack*)calloc(1, sizeof(struct Stack));
    newStack->size = 0;
    newStack->top = NULL;
}

StackElement* top(Stack* stack)
{
    return stack->top;
}

int size(Stack* stack)
{
    return stack->size;
}

bool isEmpty(Stack* stack)
{
    return size(stack) == 0;
}

void push(StackElement* newElement, Stack* stack)
{
    newElement->next = stack->top;
    stack->top = newElement;
    ++stack->size;
}

StackElement* pop(Stack* stack)
{
    if (isEmpty(stack)) {
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
    while (!isEmpty(stack)) {
        free(elementToFree);
        elementToFree = elementToFree->next;
    }
    free(stack);
}
