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

Test(vector_empty, vector_empty_true)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);

    cr_assert_eq(rvalue, 0);
    cr_assert_eq(vector.empty(&vector), true);
}

Test(vector_empty, vector_empty_false)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    cr_assert_eq(vector.empty(&vector), false);
}
