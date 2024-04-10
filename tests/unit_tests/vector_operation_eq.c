/*
 * Filename: vector_operation_eq.c
 * Path: tests/unit_tests/
 * Created Date: Tuesday, April 09th 2024, 04:17 PM
 * Author: osvegn
 *
 * Copyright (c) 2023 Vector
 */


#include <criterion/criterion.h>
#include "vector.h"

Test(vector_operation_eq, vector_operation_eq_valid)
{
    vector_t vector, copy_vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    rvalue = CAST(int, vector.at(&vector, 0));
    cr_assert_eq(rvalue, 10);
    rvalue = vector.operation_eq(&vector, &copy_vector);
    cr_assert_eq(rvalue, 0);
    cr_assert_eq(vector._size, copy_vector._size);
    cr_assert_eq(vector._element_size, copy_vector._element_size);
    cr_assert_eq(vector._capacity, copy_vector._capacity);
    int *elem = copy_vector.at(&copy_vector, 0);
    cr_assert_neq(elem, 0);
    cr_assert_eq(*elem, 10);
    vector.destructor(&vector);
}
