#include <stdio.h>

void print_array_member(int *array, unsigned int size) {
    int i = 0;

    for (i = 0; i < size; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int partition_function(int *arr, int left_index, 
    int right_index, int pivot_index) {
    
    int temp;

    while (1) {
        while (arr[left_index] < arr[pivot_index]) {
            left_index++;
        }

        while (arr[right_index] > arr[pivot_index] && right_index > 0) {
            right_index--;
        }

        if (left_index >= right_index) {
            temp = arr[pivot_index];
            arr[pivot_index] = arr[left_index];
            arr[left_index] = temp;
            return left_index;
        }
        else {
            temp = arr[right_index];
            arr[right_index] = arr[left_index];
            arr[left_index] = temp;
        }
    }       
}

void quick_sort(int *arr, int left_index, int right_index) {
    int partition, pivot;

    if (right_index - left_index <= 0) {
        return;
    }
    else {
        pivot = right_index;
        partition = partition_function(arr, left_index, right_index - 1, pivot);
        quick_sort(arr, left_index, partition - 1);
        quick_sort(arr, partition + 1, right_index);
    }
}

int main() {
    int arr[7] = {
       9, 12, 9, 2, 17, 1, 6
    };

    //int pivot = partition_function(arr, 0, 5, 6);
    //printf("pivot: %d\n", pivot);
    
    quick_sort(arr, 0, 6);
    print_array_member(arr, 7);

    return 0;
}
