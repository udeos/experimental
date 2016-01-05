#include "hashes.h"


size_t MurmurHash2 ( char *key, size_t len, int seed ) {
    const size_t m = 0x5bd1e995;
    const int r = 24;
    size_t h = seed ^ len;
    const unsigned char * data = (const unsigned char *)key;
    while(len >= 4)
    {
        size_t k = *(size_t*)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    switch(len)
    {
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8;
        case 1: h ^= data[0]; h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}
