/*
 * Filename: vector_of_vector.c
 * Path: tests/fonctional
 * Created Date: Sunday, August 20th 2023, 11:09:00 pm
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
}

int main(void)
{
    vector_t vector = {0};
    vector_t v = {0};
    int data = 0;

    if (vector_constructor(&vector, sizeof(vector_t), 0) < 0)
        my_return(1, "Failed vector constructor.");
    for (int i = 0; i < 10; i++) {
        if (vector_constructor(&v, sizeof(int), 0) < 0)
            my_return(1, "Failed v constructor.");
        for (int j = 0; j < 10; j++) {
            data = i * j;
            if (v.emplace_back(&v, &data) < 0)
                my_return(1, "Failed to emplace_back in v.");
        }
        if (vector.emplace_back(&vector, &v) < 0)
            my_return(1, "Failed to emplace_back in vector.");
    }
    while (vector.size(&vector)) {
        v = *(vector_t *)vector.back(&vector);
        v.destructor(&v);
        vector.pop_back(&vector);
    }
    vector.destructor(&vector);
    return 0;
}
