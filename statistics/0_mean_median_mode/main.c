#include <stdio.h>
#include <stdlib.h>

#define MAX 5

double mean(int *the_array, unsigned int the_array_size) {
    unsigned int i = 0;
    int sum = 0;

    for (i = 0; i < the_array_size; i++) {
        sum += the_array[i];
    }

    return (double)((double)sum / (double)the_array_size);
}

// function helper to sort
int compare_int(const void *a, const void *b) {
    if ( *(int *)a == *(int *)b ) {
        return 0;
    } else {
        return ( *(int *)a < *(int *)b ? -1 : 1); 
    }
}

int median(int *the_array, unsigned int the_array_size) {
    int i = 0;
    qsort(the_array, the_array_size, sizeof(int), compare_int);

    if (the_array_size % 2 == 0) {
        return (the_array[the_array_size / 2] + the_array[the_array_size / 2 - 1]) / 2;
    }
    else {
        return the_array[the_array_size / 2];
    }
}

// O(n^2)
int mode(int *the_array, unsigned int the_array_size) {
    int i, j;
    int temp_counter = 0;
    int highest_counter = 0;
    int mode_index = 0;

    for (i = 0; i < the_array_size; i++) {
        temp_counter = 0;
        for (j = 0; j < the_array_size; j++) {
            if (the_array[j] == the_array[i]) {
                temp_counter++;
            }
        }

        if (temp_counter > highest_counter) {
            mode_index = i;
            highest_counter = temp_counter;
        }
    }

    return the_array[mode_index];
}

int main() {
    int the_array[MAX] = {3, 2, 5, 6, 1};
    int med;
    
    printf("mean: %f\n", mean(the_array, MAX));
    printf("median: %d\n", median(the_array, MAX));
    printf("mode: %d\n", mode(the_array, MAX));
    return 0;
}