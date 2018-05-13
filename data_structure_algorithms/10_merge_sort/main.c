#include <stdio.h>

void print_array_member(int *array, unsigned int size) {
    int i = 0;

    for (i = 0; i < size; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void merge(int *array, int left_index, int middle_index, int right_index) {
    int i, j, k;
    int subarray_size_1 = middle_index - left_index + 1;
    int subarray_size_2 = right_index - middle_index;

    // temp array
    int left_array[subarray_size_1], right_array[subarray_size_2];

    for (i = 0; i < subarray_size_1; i++) {
        left_array[i] = array[left_index + i];
    }
    for (i = 0; i < subarray_size_2; i++) {
        right_array[i] = array[middle_index + i + 1];
    }

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left_index; // Initial index of merged subarray

    while (i < subarray_size_1 && j < subarray_size_2) {
        if (left_array[i] < right_array[j]) {
            array[k] = left_array[i];
            i++;
        }
        else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < subarray_size_1) {
        array[k] = left_array[i];
        i++;
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (j < subarray_size_2) {
        array[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int *array, int left_index, int right_index) {
    int middle_index = left_index + (right_index - left_index) / 2;
    if (left_index < right_index) {
        merge_sort(array, left_index, middle_index);
        merge_sort(array, middle_index + 1, right_index);

        merge(array, left_index, middle_index, right_index);
    }
}

int main() {
    int array[4] = {4, 3, 2, 1};
    print_array_member(array, 4);
    merge_sort(array, 0, 3);
    print_array_member(array, 4);
    return 0;
}