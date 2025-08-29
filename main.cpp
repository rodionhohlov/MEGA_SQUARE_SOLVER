//g++ main.cpp tester.cpp user_info.cpp string_change.cpp output.cpp solver.cpp math_operations.cpp POLTORASHKA.cpp -o program

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "math_operations.h"
#include "user_info.h"
#include "solver.h"
#include "output.h"
#include "string_change.h"
#include "tester.h"
#include "POLTORASHKA.h"
#include "cor_flag.h"

int main(int argc, char *argv[]) {

    if (argc == 1) {
        Sleep(850);

        coefs user_coefs = {.a = NAN, .b = NAN, .c = NAN}; //коэффициенты

        get_user_info(&user_coefs);

        ruts_ans solved_roots = {.x1 = NAN, .x2 = NAN, .ans = NO_ROOTS}; //корни

        solved_roots.ans = mega_solver(&user_coefs, &solved_roots); //число корней

        choose(solved_roots.ans, solved_roots.x1, solved_roots.x2);
    }

    else if ((argc == 2) && (is_flag_correct(&argv[1]))) {

        struct UnitTest test_all_cases[] = {
            {{.a = 1,  .b = 0,  .c = -1}, {.x1 = 1,   .x2 = -1,  .ans = TWO_ROOTS}},
            {{.a = 0,  .b = 1,  .c = 0},  {.x1 = 0,   .x2 = NAN, .ans = ONE_ROOT}},
            {{.a = 1,  .b = 0,  .c = 1},  {.x1 = NAN, .x2 = NAN, .ans = NO_ROOTS}},
            {{.a = 0,  .b = 0,  .c = 1},  {.x1 = NAN, .x2 = NAN, .ans = NO_ROOTS}},
            {{.a = 0,  .b = 0,  .c = 0},  {.x1 = NAN, .x2 = NAN, .ans = INF_ROOTS}},
            {{.a = 1,  .b = 0,  .c = 0},  {.x1 = 0,   .x2 = NAN, .ans = ONE_ROOT}},
            {{.a = -1, .b = 0,  .c = 0},  {.x1 = 0,   .x2 = NAN, .ans = ONE_ROOT}},
            {{.a = 1,  .b = 2,  .c = 0},  {.x1 = 0,   .x2 = -2,  .ans = TWO_ROOTS}},
            {{.a = 1,  .b = 2,  .c = -3}, {.x1 = 1,   .x2 = -3,  .ans = TWO_ROOTS}}
        };

        if (strcmp(*(argv+1), "-m") == 0 || strcmp(*(argv+1), "--menu") == 0) {
            Sleep(850);

            printf("Список флагов:\n\n");
            printf("   -m/--menu - открыть список флагов\n\n   -t/--tests - запустить unit-тесты\n\n   без символа - запустить выполнение программы\n\n   -l/--love - попробуй и узнаешь (^u^)\n");
        }

        else if (strcmp(*(argv+1), "-t") == 0 || strcmp(*(argv+1), "--tests") == 0) {
            Sleep(850);

            size_t length = sizeof(test_all_cases) / sizeof(test_all_cases[0]);

            master_test(test_all_cases, length);  //убрали амперсанд и заработало
        }

        else if (strcmp(*(argv+1), "-l") == 0 || strcmp(*(argv+1), "--love") == 0) {
            Sleep(850);

            MEOW();
        }

        else {
            Sleep(850);

            printf("Флаг недействителен\n(Введите -m/--menu, чтобы открыть список флагов)");
        }
    }

    else if (argc > 2) {
        Sleep(850);
        printf("Лишние данные");
    }

    else {
        Sleep(850);
        printf("Ошибка при введении флага \n(Введите -m/--menu, чтобы открыть список флагов\n");
    }
    return 0;
}



