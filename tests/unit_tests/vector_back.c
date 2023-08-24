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

Test(vector_back, vector_back)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    data = 5;
    vector.emplace_back(&vector, &data);
    rvalue = *(int *)vector.back(&vector);
    cr_assert_eq(rvalue, 5);
    vector.destructor(&vector);
}

Test(vector_back, vector_back_invalid_pointer)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    void *ptr;

    cr_assert_eq(rvalue, 0);
    free(vector.pointer);
    vector.pointer = NULL;
    ptr = vector.back(&vector);
    cr_assert_eq(ptr, 0);
}
