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

Test(vector_clear, vector_clear)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    vector.emplace_back(&vector, &data);
    vector.emplace_back(&vector, &data);
    vector.emplace_back(&vector, &data);
    rvalue = vector.size(&vector);
    cr_assert_eq(rvalue, 4);
    vector.clear(&vector);
    rvalue = vector.size(&vector);
    cr_assert_eq(rvalue, 0);
    vector.destructor(&vector);
}
