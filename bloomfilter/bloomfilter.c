#include <stdio.h>

#include "bloomfilter.h"
#include "hashes.h"


bloom_t *new_bloom(size_t bitmap_size, size_t seeds_count) {
    bloom_t *bloom = (bloom_t *)malloc(sizeof(bloom_t));
    if(bloom == NULL) return NULL;
    bitmap_t *bitmap = new_bitmap(bitmap_size);
    if(bitmap == NULL) return NULL;
    int *seeds = (int *)malloc(sizeof(int) * seeds_count);
    if(seeds == NULL) return NULL;
    for(size_t i = 0; i < seeds_count; ++i) {
        seeds[i] = (int)i;
    }
    bloom->bitmap = bitmap;
    bloom->seeds = seeds;
    bloom->seeds_count = seeds_count;
    return bloom;
}


void set_to_bloom(bloom_t *bloom, char *text, size_t text_len) {
    for(size_t i = 0; i < bloom->seeds_count; ++i) {
        set_bit(
                bloom->bitmap,
                MurmurHash2(text, text_len, bloom->seeds[i]) % (bloom->bitmap->size * 8)
        );
    }
}


int check_in_bloom(bloom_t *bloom, char *text, size_t text_len) {
    unsigned int bit;
    for(size_t i = 0; i < bloom->seeds_count; ++i) {
        bit = get_bit(
                bloom->bitmap,
                MurmurHash2(text, text_len, bloom->seeds[i]) % (bloom->bitmap->size * 8)
        );
        if(bit == 0) return 0;
    }
    return 1;
}



void print_bloom(bloom_t *bloom) {
    printf("seeds count: %zu\n", bloom->seeds_count);
    printf("seeds: ");
    for(size_t i = 0; i < bloom->seeds_count; ++i) {
        printf("%i ", bloom->seeds[i]);
    }
    printf("\n");
    print_bitmap(bloom->bitmap);
}
