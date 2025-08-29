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
            printf("��������� ����� %d ������\n", RootCNT);
            break;

        case ONE_ROOT:
            printf("��������� ����� %d ������: %g\n", RootCNT, root1);
            break;

        case TWO_ROOTS:
            printf("��������� ����� %d ������: %g � %g\n", RootCNT, root1, root2);
            break;

        case INF_ROOTS:
            printf("����������� ����� ������\n");
            break;

        default:
            printf("������!\n");
    }
}

