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

Test(vector_emplace, vector_emplace)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    rvalue = vector.emplace(&vector, &data, 0);
    cr_assert_eq(rvalue, 0);
    vector.destructor(&vector);
}

Test(vector_emplace, vector_emplace_high_index)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    rvalue = vector.emplace(&vector, &data, 1);
    cr_assert_eq(rvalue, -1);
    vector.destructor(&vector);
}

Test(vector_emplace, vector_emplace_null_data)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    rvalue = vector.emplace(&vector, NULL, 1);
    cr_assert_eq(rvalue, -1);
    vector.destructor(&vector);
}

Test(vector_emplace, vector_emplace_middle_index)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 5);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 5; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    rvalue = vector.emplace(&vector, &data, 1);
    cr_assert_eq(rvalue, 0);
    cr_assert_eq(*(int *)vector.at(&vector, 1), data);
    vector.destructor(&vector);
}
