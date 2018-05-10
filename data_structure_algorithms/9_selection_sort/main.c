#include <stdio.h>

void print_array_member(int *array, unsigned int size) {
    int i = 0;

    for (i = 0; i < size; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void selection_sort(int *array, unsigned int size) {
    int i, j, smallest_number;

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[i]) {
                smallest_number = array[j];
                array[j] = array[i];
                array[i] = smallest_number;
            }
        }
        print_array_member(array, 5);
    }
}

int main() {
    int the_array[5] = {5, 4, 3, 2, 1};
    print_array_member(the_array, 5);
    printf("--------\n");
    selection_sort(the_array, 5);
    printf("--------\n");
    print_array_member(the_array, 5);
    return 0;
}