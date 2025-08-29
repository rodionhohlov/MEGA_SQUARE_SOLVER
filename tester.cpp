#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "tester.h"
#include "solver.h"
#include "string_change.h"
#include "math_operations.h"

void master_test(UnitTest supertest[], size_t len) {

    for (size_t i = 0; i < len; i++)
        unit_test(&supertest[i]);
}

void unit_test(UnitTest *cur_test) {

    const coefs coefficients = {.a = cur_test->coeffits.a, .b = cur_test->coeffits.b, .c = cur_test->coeffits.c};
    ruts_ans exp_roots = {.x1 = cur_test->exp_ruts_ans.x1, .x2 = cur_test->exp_ruts_ans.x2, .ans = cur_test->exp_ruts_ans.ans};

    ruts_ans roots = {.x1 = NAN, .x2 = NAN, .ans = NO_ROOTS};

    char st1[16] = {};
    char st2[16] = {};

    printf("Уравнение с коэффициентами a = %lg b = %lg c = %lg. \n", coefficients.a, coefficients.b, coefficients.c);
    Sleep(200);
    printf("ожидаются корни x1 = %s x2 = %s и число корней - %s\n", NAN_to_str(exp_roots.x1, exp_roots.ans, st1), NAN_to_str(exp_roots.x2, exp_roots.ans, st2), string_nroots(exp_roots.ans));
    Sleep(200);

    roots.ans = mega_solver(&coefficients, &roots);

    roots.x1 = float_equivalent(roots.x1, 0) ? 0 : roots.x1;
    roots.x2 = float_equivalent(roots.x2, 0) ? 0 : roots.x2;

    bool rut1_x1 = float_equivalent(roots.x1, exp_roots.x1);
    bool rut2_x2 = float_equivalent(roots.x2, exp_roots.x2);
    bool rut2_x1 = float_equivalent(roots.x2, exp_roots.x1);
    bool rut1_x2 = float_equivalent(roots.x1, exp_roots.x2);

    if ((and_res(rut1_x1, rut2_x2) || and_res(rut2_x1, rut1_x2)) && (exp_roots.ans == roots.ans)) {
        printf("Успешный тест, получены корни x1 = %s x2 = %s. число корней - %s\n\n", NAN_to_str(roots.x1, roots.ans, st1), NAN_to_str(roots.x2, roots.ans, st2), string_nroots(roots.ans));
        Sleep(200);
    }
    else {
        printf("OH SHIT! HERE WE GO AGAIN... получены корни x1 = %s x2 = %s. число корней - %s\n\n", NAN_to_str(roots.x1, roots.ans, st1), NAN_to_str(roots.x1, roots.ans, st2), string_nroots(roots.ans));
        Sleep(200);
    }
}

