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

Test(a, a)
{
    cr_assert_eq(1, 1);
}

static int print_int_test(void *data)
{
    int value = CAST(int, data);

    printf("%i", value);
    fflush(stdout);
    return 0;
}

static void redirect_all_stdout(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test(construct_vector, construct_vector)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);

    cr_assert_eq(rvalue, 0);
    vector.destructor(&vector);
    cr_assert_eq(0, 0);
}

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
    vector.destructor()
}

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

Test(vector_at, vector_at_valid)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    rvalue = *(int *)vector.at(&vector, 0);
    cr_assert_eq(rvalue, 10);
    vector.destructor(&vector);
}

Test(vector_at, vector_at_too_high_index)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;
    void *ptr;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    ptr = vector.at(&vector, 10);
    cr_assert_eq(ptr, 0);
    vector.destructor(&vector);
}

Test(vector_at, vector_at_invalid_pointer)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    void *ptr;

    cr_assert_eq(rvalue, 0);
    free(vector.pointer);
    vector.pointer = NULL;
    vector._size = 1;
    ptr = vector.at(&vector, 0);
    cr_assert_eq(ptr, 0);
}

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

Test(vector_capacity, vector_capacity)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    unsigned int data = 0;

    cr_assert_eq(rvalue, 0);
    data = vector.capacity(&vector);
    cr_assert_eq(data, 10);
    vector.destructor(&vector);
}

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

Test(vector_pop_back, vector_pop_back_valid)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    cr_assert_eq(vector.size(&vector), 10);
    cr_assert_eq(vector.pop_back(&vector), 0);
    cr_assert_eq(vector.size(&vector), 9);
    vector.destructor(&vector);
}

Test(vector_pop_back, vector_pop_back_invalid)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    cr_assert_eq(vector.size(&vector), 0);
    cr_assert_eq(vector.pop_back(&vector), 0);
    cr_assert_eq(vector.size(&vector), 0);
    vector.destructor(&vector);
}

Test(vector_print_at, vector_print_at, .init = redirect_all_stdout)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    vector.emplace_back(&vector, &data);
    cr_assert_eq(vector.print_at(&vector, 0, &print_int_test), 0);
    cr_assert_stdout_eq_str("10");
    vector.destructor(&vector);
}

Test(vector_print_at, vector_print_at_null_function_pointer)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    vector.emplace_back(&vector, &data);
    cr_assert_eq(vector.print_at(&vector, 0, NULL), -1);
    vector.destructor(&vector);
}

Test(vector_print_at, vector_print_at_invalid_index, .init = redirect_all_stdout)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    vector.emplace_back(&vector, &data);
    cr_assert_eq(vector.print_at(&vector, 10, &print_int_test), -1);
    vector.destructor(&vector);
}

Test(vector_print, vector_print, .init = redirect_all_stdout)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);

    for (int i = 10; i < 13; i++) {
        vector.emplace_back(&vector, &i);
    }
    cr_assert_eq(vector.print(&vector, &print_int_test), 0);
    cr_assert_stdout_eq_str("[10, 11, 12]\n");
    vector.destructor(&vector);
}

Test(vector_print, vector_print_null_function_pointer)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);

    for (int i = 10; i < 13; i++) {
        vector.emplace_back(&vector, &i);
    }
    cr_assert_eq(vector.print(&vector, NULL), -1);
    vector.destructor(&vector);
}