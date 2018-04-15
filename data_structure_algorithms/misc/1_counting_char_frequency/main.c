#include <stdio.h>
#define NUMBER_OF_LETTERS 26

int hash_mapping(char c) {
    return c - 'a'; // this is to map to the specified index
}

void print_result(int *freq, unsigned int size_of_freq) {
    unsigned int i;

    for (i = 0; i < size_of_freq; i++) {
        printf("freq[%d] = %d\n", i, freq[i]);
    }
}

void count_char_frequency(char *str, unsigned int size_of_str) {
    int frequency[NUMBER_OF_LETTERS] = {0};
    unsigned int i;

    for (i = 0; i < size_of_str; i++) {
        frequency[hash_mapping(str[i])]++;
    }

    print_result(frequency, (unsigned int) NUMBER_OF_LETTERS);
}

int main()
{
    char str[9] = "aabbbcde";
    count_char_frequency(str, sizeof(str) / sizeof(char));
    return 0;
}