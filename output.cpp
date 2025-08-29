#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "output.h"
#include "solver.h"
#include "math_operations.h"

void choose(nRoots RootCNT, double root1, double root2) {

    root1 = float_equivalent(root1, 0) ? 0 : root1;
    root2 = float_equivalent(root2, 0) ? 0 : root2;

    switch(RootCNT) {

        case NO_ROOTS:
            printf("уравнение имеет %d корней\n", RootCNT);
            break;

        case ONE_ROOT:
            printf("уравнение имеет %d корень: %g\n", RootCNT, root1);
            break;

        case TWO_ROOTS:
            printf("уравнение имеет %d корней: %g и %g\n", RootCNT, root1, root2);
            break;

        case INF_ROOTS:
            printf("бесконечное число корней\n");
            break;

        default:
            printf("ошибка!\n");
    }
}

