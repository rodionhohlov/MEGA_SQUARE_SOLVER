#include <TXLib.h>
#include <stdio.h>
#include <string.h>
#include "POLTORASHKA.h"

void MEOW(void) {

    const char *print_meow[] = {"meow...", "meow...", "MEOW!"};

    for (int i = 0; i < 3; i++) {

        for (size_t k = 0; k < strlen(print_meow[i]); k++) {

            putchar(print_meow[i][k]);
            Sleep(60);
        }

        Sleep(1500);

        printf("\n");
    }
}
