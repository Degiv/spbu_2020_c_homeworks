#include "stack.h"

struct StackElement {
    int value;
    struct StackElement* next;
};

struct Stack {
    struct StackElement* top;
    int size;
};

StackElement* createStackElement(int value)
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

int getValue(StackElement* stackElement)
{
    return stackElement->value;
}

void setValue(StackElement* stackElement, int value)
{
    stackElement->value = value;
}

int getSize(Stack* stack)
{
    return stack->size;
}

bool isEmpty(Stack* stack)
{
    return getSize(stack) == 0;
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
