/*
 * Filename: vector_of_int.c
 * Path: tests/fonctional
 * Created Date: Sunday, August 20th 2023, 12:30:40 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 Vector
 */

#include "vector.h"
#include <stdio.h>

static int my_return(int value, char *message)
{
    printf("%s\n", message);
    fflush(stdout);
    return value;
}

int main(void)
{
    vector_t vector, copy_vector = {0};
    int rvalue = vector_constructor(&vector, sizeof(int), 0);

    if (rvalue < 0)
        return my_return(rvalue, "Constructor failure.");
    for (int i = 0; i < 10; i++) {
        rvalue = vector.emplace_back(&vector, &i);
        if (rvalue < 0)
            return my_return(rvalue, "Emplace_back failure.");
    }
    rvalue = vector.operation_eq(&vector, &copy_vector);
    if (rvalue < 0)
        return my_return(rvalue, "operation_eq failure.");
    if (CAST(int, vector.front(&vector)) != 0)
        return my_return(rvalue, "Front failure.");
    if (CAST(int, vector.front(&vector)) != CAST(int, copy_vector.front(&copy_vector)))
        return my_return(-1, "Dest and Src differ.");
    vector.destructor(&vector);
    return 0;
}
