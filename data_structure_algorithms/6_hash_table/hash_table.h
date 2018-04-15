#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#define HASH_TABLE_SIZE 20

struct ht_data_item_string {
    char key[32];
    char value[32];
};

extern struct ht_data_item_string *ht_hash_array_string[HASH_TABLE_SIZE];

void ht_insert(struct ht_data_item_string *item);
struct ht_data_item_string *ht_search(char *key);

#endif