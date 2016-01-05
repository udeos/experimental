#ifndef EXPERIMENTAL_UTILS_H
#define EXPERIMENTAL_UTILS_H

#include <stddef.h>
#include <stdlib.h>

typedef struct string_t {
    char *data;
    size_t size;
} string_t;


void generate_string(char *str, size_t size);
void generate_test_data(string_t *test_data, size_t size);

#endif //EXPERIMENTAL_UTILS_H
