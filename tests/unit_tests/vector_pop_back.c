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

Test(vector_pop_back, vector_pop_back_valid)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    cr_assert_eq(vector.size(&vector), 10);
    cr_assert_eq(vector.pop_back(&vector), 0);
    cr_assert_eq(vector.size(&vector), 9);
    vector.destructor(&vector);
}

Test(vector_pop_back, vector_pop_back_invalid)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    cr_assert_eq(vector.size(&vector), 0);
    cr_assert_eq(vector.pop_back(&vector), 0);
    cr_assert_eq(vector.size(&vector), 0);
    vector.destructor(&vector);
}
