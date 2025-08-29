#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

struct coefs {
    double a;
    double b;
    double c;
};

enum nRoots {
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = -1
};

struct ruts_ans {
    double x1;
    double x2;
    nRoots ans;
};

void solve_standard_square(const coefs *coefficients, ruts_ans *roots);
void solve_linal(const coefs *coefficients, ruts_ans *roots);
void solve_square(const coefs *coefficients, ruts_ans *roots);

nRoots mega_solver(const coefs *coefficients, ruts_ans *roots);

double discrim(const coefs *coefficients);

#endif
