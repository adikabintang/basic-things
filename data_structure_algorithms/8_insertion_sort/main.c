#include <stdio.h>

void print_array_member(int *array, unsigned int size) {
    int i = 0;

    for (i = 0; i < size; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void insertion_sort(int *array, int size) {
    int i, j, temp;

    for (i = 1; i < size; i++) {
        j = i;
        temp = array[i];
        while (temp < array[j-1] && j >= 0) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = temp;
        printf("j: %d -> ", j);
        print_array_member(array, 5);
    }
}

int main() {
    int the_array[5] = {1, 4, 3, 2, 5};
    print_array_member(the_array, 5);
    printf("--------\n");
    insertion_sort(the_array, 5);
    printf("--------\n");
    print_array_member(the_array, 5);
    return 0;
}