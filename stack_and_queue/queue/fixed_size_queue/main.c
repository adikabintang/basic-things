#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE_MAX 5

bool queue_enqueue(int *queue, unsigned int *rear_position, int data, unsigned int queue_size) {
    if (*rear_position >= queue_size)
        return false;
    
    queue[*rear_position] = data;
    (*rear_position)++;
    return true;
}

void queue_dequeue(int *queue, unsigned int *rear_position) {
    unsigned int i = 0;

    (*rear_position)--;
    for (i = 0; i < *rear_position; i++) {
        queue[i] = queue[i + 1];
    }
}

void queue_print_all(int *queue, unsigned int rear_position) {
    unsigned int i = 0;

    for (i = 0; i < rear_position; i++) {
        printf("\t%d\n", queue[i]);
    }
}

int main()
{
    int my_queue[ARRAY_SIZE_MAX] = {0};
    unsigned int rear_pos = 0;
    
    printf("queue...\n");
    queue_enqueue(my_queue, &rear_pos, 5, ARRAY_SIZE_MAX);
    queue_enqueue(my_queue, &rear_pos, 6, ARRAY_SIZE_MAX);
    queue_enqueue(my_queue, &rear_pos, 7, ARRAY_SIZE_MAX);
    queue_enqueue(my_queue, &rear_pos, 8, ARRAY_SIZE_MAX);

    queue_print_all(my_queue, rear_pos);

    printf("dequeue...\n");
    queue_dequeue(my_queue, &rear_pos);

    queue_print_all(my_queue, rear_pos);

    return 0;
}