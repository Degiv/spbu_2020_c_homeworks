#include "../../library/commonUtils/numericOperations.h"
#include <stdio.h>

int main()
{
    printf("Enter index of Fibonacci number:\n");
    int index = 0;
    scanf("%d", &index);
    printf("Your Fibonacci number: %d", getFibonacciNumber(index));
}
