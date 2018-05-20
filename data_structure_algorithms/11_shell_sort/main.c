#include <stdio.h>

void print_array_member(int *array, unsigned int size) {
    int i = 0;

    for (i = 0; i < size; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void shell_sort(int *array, int size) {
    int gap;
    int i = 0, temp = 0;

    for (gap = size / 2; gap >= 1; gap = gap / 2) {
        for (i = gap; i < size; i++) {
            if (array[i] < array[i - gap]) {
                temp = array[i];
                array[i] = array[i - gap];
                array[i - gap] = temp;
            }
        }
    }
}

int main() {
    //int the_array[8] = {1, 3, 2, 4, 6, 5, 8, 7};
    int the_array[5] = {12, 34, 54, 2, 3};
    
    print_array_member(the_array, 5);
    shell_sort(the_array, 5);
    print_array_member(the_array, 5);
    return 0;
}