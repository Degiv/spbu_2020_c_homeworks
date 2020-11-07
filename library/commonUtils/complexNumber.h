#ifndef SPBU_2020_C_HOMEWORKS_COMPLEXNUMBER_H
#define SPBU_2020_C_HOMEWORKS_COMPLEXNUMBER_H

typedef struct ComplexNumber {
    double real;
    double imaginary;
} ComplexNumber;
ComplexNumber getAddition(ComplexNumber first, ComplexNumber second);

ComplexNumber getSubtraction(ComplexNumber first, ComplexNumber second);

ComplexNumber getMultiplication(ComplexNumber first, ComplexNumber second);

ComplexNumber getDivision(ComplexNumber first, ComplexNumber second);

#endif //SPBU_2020_C_HOMEWORKS_COMPLEXNUMBER_H
