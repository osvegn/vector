/*
 * Filename:vector_tests.c
 * Path: tests/library/vector
 * Created Date: Thursday, December 29th 2022, 10:41:19 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 ECS
 */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "vector.h"

static int print_int_test(void *data)
{
    int value = CAST(int, data);

    printf("%i", value);
    fflush(stdout);
    return 0;
}

static void redirect_all_stdout(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test(vector_print, vector_print, .init = redirect_all_stdout)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);

    for (int i = 10; i < 13; i++) {
        vector.emplace_back(&vector, &i);
    }
    cr_assert_eq(vector.print(&vector, &print_int_test), 0);
    cr_assert_stdout_eq_str("[10, 11, 12]\n");
    vector.destructor(&vector);
}

Test(vector_print, vector_print_null_function_pointer)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);

    for (int i = 10; i < 13; i++) {
        vector.emplace_back(&vector, &i);
    }
    cr_assert_eq(vector.print(&vector, NULL), -1);
    vector.destructor(&vector);
}
