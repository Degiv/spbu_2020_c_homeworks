#include "complexNumber.h"

ComplexNumber getAddition(ComplexNumber first, ComplexNumber second)
{
    ComplexNumber addition;
    addition.real = first.real + second.real;
    addition.imaginary = first.imaginary + second.imaginary;
    return addition;
}

ComplexNumber getSubtraction(ComplexNumber first, ComplexNumber second)
{
    ComplexNumber subtraction;
    subtraction.real = first.real - second.real;
    subtraction.imaginary = first.imaginary - second.imaginary;
    return subtraction;
}

ComplexNumber getMultiplication(ComplexNumber first, ComplexNumber second)
{
    ComplexNumber multiplication;
    multiplication.real = first.real * second.real - first.imaginary * second.imaginary;
    multiplication.imaginary = first.real * second.imaginary - first.imaginary * second.real;
    return multiplication;
}

ComplexNumber getDivision(ComplexNumber first, ComplexNumber second)
{
    ComplexNumber division;
    double denominator = second.real * second.real + second.imaginary * second.imaginary;
    division.real = (first.real * second.real + first.imaginary * second.imaginary) / denominator;
    division.imaginary = (first.imaginary * second.real - first.real * second.imaginary) / denominator;
    return division;
}