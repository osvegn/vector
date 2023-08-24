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

Test(vector_emplace_back, vector_emplace_back)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    rvalue = vector.emplace_back(&vector, &data);
    cr_assert_eq(rvalue, 0);
    vector.destructor(&vector);
}

Test(vector_emplace_back, vector_emplace_back_null_data)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(char), 0);
    char data = 10;

    cr_assert_eq(rvalue, 0);
    rvalue = vector.emplace_back(&vector, NULL);
    cr_assert_eq(rvalue, -1);
    vector.destructor(&vector);
}
