#include <stdio.h>

#include "bitmap.h"


bitmap_t *new_bitmap(size_t bitmap_size) {
    bitmap_t *bitmap = (bitmap_t *)malloc(sizeof(bitmap_t));
    if(bitmap == NULL) return NULL;
    char *bytes = (char *)malloc(bitmap_size);
    if(bytes == NULL) return NULL;
    bitmap->bytes = bytes;
    bitmap->size = bitmap_size;
    return bitmap;
}


void set_bit(bitmap_t *bitmap, size_t n) {
    bitmap->bytes[n / 8] |= 1 << (n & 7);
}


void unset_bit(bitmap_t *bitmap, size_t n) {
    bitmap->bytes[n / 8] &= ~(1 << (n & 7));
}


unsigned int get_bit(bitmap_t *bitmap, size_t n) {
    return bitmap->bytes[n / 8] & (1 << (n & 7)) ? 1 : 0;
}


void print_bitmap(bitmap_t *bitmap) {
    char c;
    size_t i, j;
    printf("size: %zu\n", bitmap->size);
    printf("bytes: ");
    for(i=0; i < bitmap->size; ++i) {
        c = bitmap->bytes[i];
        for(j = 0; j <= 7; ++j) {
            putchar((c & (1 << j)) ? '1' : '0');
        }
        putchar(' ');
    }
    printf("\n");
}
