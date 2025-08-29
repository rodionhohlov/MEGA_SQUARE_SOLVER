#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "string_change.h"
#include "solver.h"

const char *string_nroots(nRoots cnt) {

    switch(cnt) {
        case ONE_ROOT:
            return "один";

        case TWO_ROOTS:
            return "два";

        case NO_ROOTS:
            return "нисколько";

        case INF_ROOTS:
            return "много";

        default:
            return "ОУ ГАДЭМ ошибка";
    }
}

const char *NAN_to_str(double root, nRoots ruts, char *super_string) {
    if (isnan(root)) {

        switch (ruts) {
            case NO_ROOTS:
            case ONE_ROOT:
                return "нет";

            case INF_ROOTS:
                return "неопределённо";

            case TWO_ROOTS:
            default:
                return "ошибка новичка";
        }
    }

    sprintf(super_string, "%lg", root);

    return super_string;
}
