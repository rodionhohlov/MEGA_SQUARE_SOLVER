#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "user_info.h"
#include "solver.h"

void get_user_info(coefs *coefficients) {

    assert(coefficients);

    printf("Ёта программа решает квадратные уравнени€\n");
    printf("¬ведите коэффициенты уравнени€\n");

    coefficients->a = get_num(&coefficients->a, 'a');
    coefficients->b = get_num(&coefficients->b, 'b');
    coefficients->c = get_num(&coefficients->c, 'c');
}

double get_num(double *coef, char ch) {

    assert(coef);

    int sym = 0;

    printf("%c = ", ch);

    while (((scanf("%lg", coef) != 1) || (getchar() != '\n'))) {
        while ((sym = getchar()) != '\n')
            continue;

        printf("¬ведите число >:(\n");
        printf("%c = ", ch);
    }

    return *coef;

}
