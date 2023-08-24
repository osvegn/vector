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

Test(vector_front, vector_front)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    data = 5;
    vector.emplace_back(&vector, &data);
    rvalue = *(int *)vector.front(&vector);
    cr_assert_eq(rvalue, 10);
    vector.destructor(&vector);
}
