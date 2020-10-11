#include "../../library/commonUtils/stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_OF_EXPRESSION 1000

bool isDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

bool isSign(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int getComponent(char* expression, int* position)
{
    int component = 0;
    while (isDigit(expression[*position])) {
        component = component * 10 + expression[*position] - '0';
        ++(*position);
    }
    --(*position);
    return component;
}

int calculate(int firstComponent, int secondComponent, char sign)
{
    if (sign == '+') {
        return firstComponent + secondComponent;
    } else if (sign == '-') {
        return firstComponent - secondComponent;
    } else if (sign == '*') {
        return firstComponent * secondComponent;
    } else if (sign == '/' && secondComponent != 0) {
        return firstComponent / secondComponent;
    }
    return 0;
}

int calculateExpression(char* expression)
{
    int expressionSize = strlen(expression);
    Stack* components = createStack();
    StackElement* currentComponent = NULL;
    for (int i = 0; i < expressionSize; ++i) {
        if (isDigit(expression[i])) {
            currentComponent = createStackElement(getComponent(expression, &i));
            push(currentComponent, components);

        } else if (isSign(expression[i]) && getSize(components) > 1) {
            StackElement* secondComponent = pop(components);
            StackElement* firstComponent = pop(components);
            currentComponent = createStackElement(calculate(getValue(firstComponent), getValue(secondComponent), expression[i]));
            push(currentComponent, components);

            free(secondComponent);
            free(firstComponent);
        }
    }

    StackElement* lastComponent = pop(components);
    int resultOfExpression = getValue(lastComponent);
    free(lastComponent);
    freeStack(components);
    return resultOfExpression;
}

bool test1IsPassed()
{
    char expression[] = { "1 49 23 27 33 17 15 35 42 8 + + + + + + + + +" };
    return calculateExpression(expression) == 250;
}

bool test2IsPassed()
{
    char expression[] = { "1 2 3 * * 6 2 / /" };
    return calculateExpression(expression) == 2;
}

bool test3IsPassed()
{
    char expression[] = { "23 2 * 1000 100 - + 10 /" };
    return calculateExpression(expression) == 94;
}

bool test4IsPassed()
{
    char expression[] = { "1 2 3 4 5 * * * *" };
    return calculateExpression(expression) == 120;
}

bool test5IsPassed()
{
    char expression[] = { "1004123 10000 / 10047538 100000 / 50029457 100000 / 300658 1000 / + + +" };
    return calculateExpression(expression) == 1000;
}

bool arePassed()
{
    return test1IsPassed() && test2IsPassed() && test3IsPassed() && test4IsPassed() && test5IsPassed();
}

int main()
{
    if (arePassed()) {
        printf("All tests have been passed\n");
    } else {
        printf("Some tests have been failed\n");
    }

    char expression[MAX_SIZE_OF_EXPRESSION] = { ' ' };
    printf("Input expression in postfix notation:\n");
    scanf("%1000[^\n]", expression); // 1000 is MAX_SIZE_OF_EXPRESSION

    printf("Result is: %d", calculateExpression(expression));

    return 0;
}
