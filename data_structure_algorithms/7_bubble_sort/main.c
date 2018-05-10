#include <stdio.h>
#include <stdbool.h>

void sorting_bubble_sort(int *array, unsigned int size) {
    int i = 0;
    int j = 0;
    int temp;
    bool is_swapped = false;

    int steps = 0;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                is_swapped = true;
            }
            steps++;
        }

        if (!is_swapped) {
            break;
        }
    }

    printf("bubble_sort steps: %d\n", steps);
}

void print_array_member(int *array, unsigned int size) {
    int i = 0;

    for (i = 0; i < size; i++) {
        printf("%d  ", array[i]);
    }
}

int main()
{
    int the_array[5] = {5, 4, 3, 2, 1};

    printf("before sorted: ");
    print_array_member(the_array, 5);
    sorting_bubble_sort(the_array, 5);
    printf("\nafter sorted: ");
    print_array_member(the_array, 5);
    
    return 0;
}