#include <stdio.h>

#include "bloomfilter/bloomfilter.h"
#include "bloomfilter/utils.h"


void test_bloom(bloom_t *bloom) {
    size_t known_objects_size = 200;
    string_t known_objects[known_objects_size];
    generate_test_data(known_objects, known_objects_size);
    for(size_t i = 0; i < known_objects_size; ++i) {
        set_to_bloom(bloom, known_objects[i].data, known_objects[i].size);
    }

    // test: all known objects found
    size_t known_objects_found = 0;
    for(size_t i = 0; i < known_objects_size; ++i) {
        known_objects_found += check_in_bloom(bloom, known_objects[i].data, known_objects[i].size);
    }
    printf("Known objects found: %zu\n", known_objects_found);

    // test: unknown objects found
    size_t unknown_objects_size = 100;
    string_t unknown_objects[unknown_objects_size];
    generate_test_data(unknown_objects, unknown_objects_size);
    size_t unknown_objects_found = 0;
    for(size_t i = 0; i < unknown_objects_size; ++i) {
        unknown_objects_found += check_in_bloom(bloom, unknown_objects[i].data, unknown_objects[i].size);
    }
    printf("Unknown object found: %zu\n", unknown_objects_found);
}



int main() {
    bloom_t *bloom = new_bloom(1000, 10);
    test_bloom(bloom);

    return 0;
}
