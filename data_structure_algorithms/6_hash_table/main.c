#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"

int main()
{  
    struct ht_data_item_string *data;
    data = malloc(sizeof(struct ht_data_item_string));
    
    strcpy(data->key, "bintang");
    strcpy(data->value, "0856");
    
    ht_insert(data);

    strcpy(data->key, "mela");
    strcpy(data->value, "0877");
    
    ht_insert(data);

    data = ht_search("bintang");
    
    if (data != NULL) {
        printf("value: %s\n", data->value);
    }
    else {
        printf("not found\n");
    }

    return 0;
}