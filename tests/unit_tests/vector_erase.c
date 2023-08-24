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

Test(vector_erase, vector_erase_valid)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    cr_assert_eq(vector.erase(&vector, 1), 0);
    cr_assert_eq(*(int *)vector.at(&vector, 1), 12);
    vector.destructor(&vector);
}

Test(vector_erase, vector_erase_invalid)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    cr_assert_eq(vector.erase(&vector, 11), -1);
    vector.destructor(&vector);
}

Test(vector_erase, vector_erase_limite_value)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    cr_assert_eq(vector.erase(&vector, 10), -1);
    vector.destructor(&vector);
}
