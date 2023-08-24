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

Test(vector_shrink_to_fit, vector_shrink_to_fit_failure)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);

    cr_assert_eq(rvalue, 0);
    cr_assert_eq(vector.capacity(&vector), 10);
    cr_assert_eq(vector.shrink_to_fit(&vector), -1);
    cr_assert_eq(vector.capacity(&vector), 0);
    vector.destructor(&vector);
}

Test(vector_shrink_to_fit, vector_shrink_to_fit_success)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    cr_assert_eq(vector.capacity(&vector), 10);
    cr_assert_eq(vector.shrink_to_fit(&vector), 0);
    cr_assert_eq(vector.capacity(&vector), 1);
    vector.destructor(&vector);
}
