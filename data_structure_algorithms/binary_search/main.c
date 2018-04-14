#include <stdio.h>

#define ARRAY_SIZE 10
#define BS_SEARCH_NOT_FOUND -1

int bs_search(int *array, int searched_data, unsigned int array_size) {
    unsigned int low = 0;
    unsigned int high = array_size - 1;
    unsigned int mid = 0;
    
    while (high >= low) {
        mid = low + (high - low) / 2;
        
        if (searched_data == array[mid]) {
            return mid;
        } 
        else if (searched_data > array[mid]) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    return BS_SEARCH_NOT_FOUND;
}

int main()
{
    int my_array[ARRAY_SIZE] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    
    int index_search = bs_search(my_array, 19, ARRAY_SIZE);
    if (index_search == BS_SEARCH_NOT_FOUND) {
        printf("not found\n");
    }
    else {
        printf("found at %d\n", index_search);
    }
    
    return 0;
}