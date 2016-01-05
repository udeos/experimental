#ifndef EXPERIMENTAL_BLOOMFILTER_H
#define EXPERIMENTAL_BLOOMFILTER_H

#include "bitmap.h"


typedef struct bloom_t {
    bitmap_t *bitmap;
    int *seeds;
    size_t seeds_count;
} bloom_t;


bloom_t *new_bloom(size_t bitmap_size, size_t seeds_count);
//bloom_t *optimal_bloom(size_t threshold, double error_probability);
void print_bloom(bloom_t *bloom);
void set_to_bloom(bloom_t *bloom, char *text, size_t text_len);
int check_in_bloom(bloom_t *bloom, char *text, size_t text_len);


#endif //EXPERIMENTAL_BLOOMFILTER_H
