#include "hash_table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ht_data_item_string *ht_hash_array_string[HASH_TABLE_SIZE] = { NULL };

unsigned int ht_hash_string_to_int(char *str) {
    unsigned int value = 0;
    unsigned int i;
    unsigned int str_len = strlen(str);

    for (i = 0; i < str_len; i++) {
        value += str[i];
    }

    return value;
}

int ht_hash_index(int key) {
    return key % HASH_TABLE_SIZE;
}

void ht_insert(struct ht_data_item_string *item)
{
    unsigned int index = ht_hash_index(ht_hash_string_to_int(item->key));

    ht_hash_array_string[index] = 
        malloc(sizeof(struct ht_data_item_string));
    
    strcpy(ht_hash_array_string[index]->key, item->key);
    strcpy(ht_hash_array_string[index]->value, item->value);    
}

struct ht_data_item_string *ht_search(char *key) {
    unsigned int index = ht_hash_index(ht_hash_string_to_int(key));

    return ht_hash_array_string[index];
} 