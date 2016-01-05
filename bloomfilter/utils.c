#include "utils.h"



void generate_string(char *str, size_t size) {
    static char charset[] = "0123456789"
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t  index,
            charset_size = sizeof(charset) - 1;
    for(size_t i = 0; i < size; ++i) {
        index = rand() % charset_size;
        str[i] = charset[index];
    }
}


void generate_test_data(string_t *test_data, size_t size) {
    size_t  data_len,
            max_length = 100;
    for(size_t i = 0; i < size; ++i) {
        data_len = rand() % max_length;
        string_t string;
        string.data = malloc(sizeof(char) * data_len);
        generate_string(string.data, data_len);
        string.size = data_len;
        test_data[i] = string;
    }
}