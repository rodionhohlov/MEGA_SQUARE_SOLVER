#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "cor_flag.h"

bool is_flag_correct(char *flag[]) {

    const char *flag_catalog[] = {"-m", "--menu", "-t", "--tests", "-l", "--love"};

    for (size_t i = 0; i < (sizeof(flag_catalog) / sizeof(flag_catalog[0])); i++) {

        if (strcmp(*flag, flag_catalog[i]) == 0)

            return true;
    }

    return false;
}
