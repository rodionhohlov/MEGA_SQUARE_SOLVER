#ifndef TESTER_H_INCLUDED
#define TESTER_H_INCLUDED

#include "solver.h"

struct UnitTest {
    struct coefs coeffits;
    struct ruts_ans exp_ruts_ans;
};

void master_test(UnitTest supertest[], size_t len);

void unit_test(UnitTest *cur_test);

#endif
