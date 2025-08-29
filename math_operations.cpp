#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "math_operations.h"

bool float_equivalent(double num1, double num2) {
    if (isnan(num1) && isnan(num2))
        return true;

    if ((fabs(num1 - num2)) < EPSILON)
        return true;

    return false;
}

bool and_res(bool arg1, bool arg2) {
    return (arg1 && arg2);
}
