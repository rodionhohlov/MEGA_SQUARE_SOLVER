#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solver.h"
#include "math_operations.h"

#define NAN_COEF_ASSERT(ex) if(!(ex)) {printf("файл %s строка %d: коэффициент имеет значение NAN", __FILE__, __LINE__); abort();}

nRoots mega_solver(const coefs *coefficients, ruts_ans *roots) {

    assert(roots);
    assert(coefficients);
    NAN_COEF_ASSERT(!isnan(coefficients->a));
    NAN_COEF_ASSERT(!isnan(coefficients->b));
    NAN_COEF_ASSERT(!isnan(coefficients->c));

    roots->ans = NO_ROOTS;

    if (float_equivalent(coefficients->a, 0))
        solve_linal(coefficients, roots);
    else
        solve_square(coefficients, roots);

    return roots->ans;
}

void solve_square(const coefs *coefficients, ruts_ans *roots) {

    assert(roots);
    assert(coefficients);
    NAN_COEF_ASSERT(!isnan(coefficients->a));
    NAN_COEF_ASSERT(!isnan(coefficients->b));
    NAN_COEF_ASSERT(!isnan(coefficients->c));

    if (float_equivalent(coefficients->b, 0)) {

        if (float_equivalent(coefficients->c, 0)) {
            roots->ans = ONE_ROOT;
            roots->x1 = 0;
        }
        else if ((coefficients->a * coefficients->c) <= 0) {
            double rut_sq = sqrt(-coefficients->c/coefficients->a);

            roots->x1 =  rut_sq;
            roots->x2 = -rut_sq;
            roots->ans = TWO_ROOTS;
        }
        else
            roots->ans = NO_ROOTS;
    }
    else {
        if (float_equivalent(coefficients->c, 0)) {
            roots->x1 = 0;
            roots->x2 = (-coefficients->b)/coefficients->a;
            roots->ans = TWO_ROOTS;
        }
        else
            solve_standard_square(coefficients, roots);
    }
}

void solve_linal(const coefs *coefficients, ruts_ans *roots) {

    assert(roots);
    assert(coefficients);
    NAN_COEF_ASSERT(!isnan(coefficients->a));
    NAN_COEF_ASSERT(!isnan(coefficients->b));
    NAN_COEF_ASSERT(!isnan(coefficients->c));


    if (float_equivalent(coefficients->b, 0)) {
        if (float_equivalent(coefficients->c, 0))
            roots->ans = INF_ROOTS;
        else
            roots->ans = NO_ROOTS;
    }
    else {
        roots->ans = ONE_ROOT;
        roots->x1 = -(coefficients->c/coefficients->b);
    }
}

double discrim(const coefs *coefficients) {

    assert(coefficients);

    return coefficients->b*coefficients->b - 4*coefficients->a*coefficients->c;
}

void solve_standard_square(const coefs *coefficients, ruts_ans *roots) {

    assert(roots);
    assert(coefficients);
    NAN_COEF_ASSERT(!isnan(coefficients->a));
    NAN_COEF_ASSERT(!isnan(coefficients->b));
    NAN_COEF_ASSERT(!isnan(coefficients->c));


    double disc = discrim(coefficients);  //дискриминант

    if (disc < 0) {

        roots->ans = NO_ROOTS;
        return;
    }
    else {

        double sq_disc = sqrt(disc);

        roots->x1 = (-coefficients->b + sq_disc)/(2*coefficients->a);
        roots->x2 = (-coefficients->b - sq_disc)/(2*coefficients->a);
    }

    if (float_equivalent(roots->x1, roots->x2))
        roots->ans = ONE_ROOT;
    else
        roots->ans = TWO_ROOTS;
}
