#ifndef EXPERIMENTAL_BITMAP_H
#define EXPERIMENTAL_BITMAP_H

#include <stdlib.h>


typedef struct bitmap_t {
    char *bytes;
    size_t size;
} bitmap_t;


bitmap_t *new_bitmap(size_t bitmap_size);
void set_bit(bitmap_t *bitmap, size_t n);
void unset_bit(bitmap_t *bitmap, size_t n);
unsigned int get_bit(bitmap_t *bitmap, size_t n);
void print_bitmap(bitmap_t *bitmap);


#endif //EXPERIMENTAL_BITMAP_H
