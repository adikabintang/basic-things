#include <stdio.h>

#define ARRAY_SIZE 10
#define INTERPOLATION_SEARCH_NOT_FOUND -1

int interpolation_search(int *array, int searched_data, unsigned int array_size) {
    unsigned int low = 0;
    unsigned int high = ARRAY_SIZE - 1;
    unsigned int probbed_position;

    while (high >= low) {
        probbed_position = low + ( (searched_data - array[low]) * (high - low)
            / (array[high] - array[low]) );
            
        if (array[probbed_position] == searched_data) {
            return probbed_position;
        }
        else if (array[probbed_position] > searched_data) {
            high = probbed_position - 1;
        }
        else {
            low = probbed_position + 1;
        }

        
    }

    return INTERPOLATION_SEARCH_NOT_FOUND;
}

int main()
{
    int my_array[ARRAY_SIZE] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    
    int index_search = interpolation_search(my_array, 44, ARRAY_SIZE);
    if (index_search == INTERPOLATION_SEARCH_NOT_FOUND) {
        printf("not found\n");
    }
    else {
        printf("found at %d\n", index_search);
    }
    
    return 0;
}