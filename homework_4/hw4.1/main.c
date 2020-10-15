#include "../../library/commonUtils/arrayOperations.h"
#include "../../library/commonUtils/stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

bool isOperator(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

double parseComponent(char* expression, int* position)
{
    char** tail = NULL;
    double component = strtod(&expression[*position], tail);
    while (isDigit(expression[*position]) || expression[*position] == '.') {
        ++(*position);
    }
    --(*position);
    return component;
}

double calculate(double firstComponent, double secondComponent, char operatorSymbol)
{
    if (operatorSymbol == '+') {
        return firstComponent + secondComponent;
    } else if (operatorSymbol == '-') {
        return firstComponent - secondComponent;
    } else if (operatorSymbol == '*') {
        return firstComponent * secondComponent;
    } else if (operatorSymbol == '/' && secondComponent != 0) {
        return firstComponent / secondComponent;
    }
    return 0;
}

double calculateExpression(char* expression)
{
    int expressionSize = strlen(expression);
    Stack* components = createStack();
    StackElement* currentComponent = NULL;
    for (int i = 0; i < expressionSize; ++i) {
        if (isDigit(expression[i])) {
            currentComponent = createStackElement(parseComponent(expression, &i));
            push(currentComponent, components);
        } else if (isOperator(expression[i]) && getSizeOfStack(components) > 1) {
            StackElement* secondComponent = pop(components);
            StackElement* firstComponent = pop(components);
            currentComponent = createStackElement(calculate(getValueSE(firstComponent), getValueSE(secondComponent), expression[i]));
            push(currentComponent, components);

            free(secondComponent);
            free(firstComponent);
        }
    }

    StackElement* lastComponent = pop(components);
    double resultOfExpression = getValueSE(lastComponent);
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
    return calculateExpression(expression) == 94.6;
}

bool test4IsPassed()
{
    char expression[] = { "1 2 3 4 5 * * * *" };
    return calculateExpression(expression) == 120;
}

bool test5IsPassed()
{
    char expression[] = { "104 2 / 2 / 2 / 2 / 2 /" };
    return calculateExpression(expression) == 3.25;
}

bool allTestsArePassed()
{
    return test1IsPassed() && test2IsPassed() && test3IsPassed() && test4IsPassed() && test5IsPassed();
}

int main()
{
    if (allTestsArePassed()) {
        printf("All tests have been passed\n");
    } else {
        printf("Some tests have been failed\n");
    }

    printf("Input expression in postfix notation:\n");
    char* expression = createString();
    printf("Result is: %f", calculateExpression(expression));

    free(expression);
    return 0;
}
