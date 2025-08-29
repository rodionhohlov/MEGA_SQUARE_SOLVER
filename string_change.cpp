#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "string_change.h"
#include "solver.h"

const char *string_nroots(nRoots cnt) {

    switch(cnt) {
        case ONE_ROOT:
            return "����";

        case TWO_ROOTS:
            return "���";

        case NO_ROOTS:
            return "���������";

        case INF_ROOTS:
            return "�����";

        default:
            return "�� ����� ������";
    }
}

const char *NAN_to_str(double root, nRoots ruts, char *super_string) {
    if (isnan(root)) {

        switch (ruts) {
            case NO_ROOTS:
            case ONE_ROOT:
                return "���";

            case INF_ROOTS:
                return "������������";

            case TWO_ROOTS:
            default:
                return "������ �������";
        }
    }

    sprintf(super_string, "%lg", root);

    return super_string;
}
