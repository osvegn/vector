/*
 * Filename: vector_of_string.c
 * Path: tests/fonctional
 * Created Date: Sunday, August 20th 2023, 11:09:00 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 Vector
 */

#include "vector.h"
#include <string.h>
#include <stdio.h>

static int my_return(int value, char *message)
{
    printf("%s\n", message);
    fflush(stdout);
}

int main(void)
{
    vector_t vector = {0};
    int rvalue = vector_constructor(&vector, sizeof(void *), 0);
    char *av[] = {"./program", "test", "test2"};

    if (rvalue < 0)
        return my_return(rvalue, "Constructor failure.");
    for (int i = 0; i < 3; i++) {
        rvalue = vector.emplace_back(&vector, &av[i]);
        if (rvalue < 0)
            return my_return(rvalue, "Emplace_back failure.");
    }
    if (strcmp(CAST(char *, vector.front(&vector)), av[0]))
        return my_return(rvalue, "Front failure.");
    vector.destructor(&vector);
    return 0;
}
