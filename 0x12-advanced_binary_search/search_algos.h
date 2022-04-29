#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
int backtrack(int *array, int index, int value);
int binary_search(int *array, size_t size, int left, int right, int value);
void print_array(int *array, int left, int right);

#endif
