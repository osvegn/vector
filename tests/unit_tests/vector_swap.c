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

Test(vector_swap, vector_swap_valid)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    vector.swap(&vector, 0, 1);
    rvalue = *(int *)vector.at(&vector, 0);
    cr_assert_eq(rvalue, 11);
    rvalue = *(int *)vector.at(&vector, 1);
    cr_assert_eq(rvalue, 10);
    vector.destructor(&vector);
}

Test(vector_swap, vector_swap_element1_invalid_size)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    vector.swap(&vector, 100, 1);
    rvalue = *(int *)vector.at(&vector, 0);
    cr_assert_eq(rvalue, 10);
    rvalue = *(int *)vector.at(&vector, 1);
    cr_assert_eq(rvalue, 11);
    vector.destructor(&vector);
}

Test(vector_swap, vector_swap_element2_invalid_size)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    vector.swap(&vector, 1, 100);
    rvalue = *(int *)vector.at(&vector, 0);
    cr_assert_eq(rvalue, 10);
    rvalue = *(int *)vector.at(&vector, 1);
    cr_assert_eq(rvalue, 11);
    vector.destructor(&vector);
}