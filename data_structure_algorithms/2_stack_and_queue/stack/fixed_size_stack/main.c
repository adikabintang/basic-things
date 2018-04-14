#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 5

int stack_peek(int *stack, unsigned int top_position) {
    return stack[top_position];
}

bool stack_is_full(unsigned int top_position, unsigned int stack_size) {
    return (top_position == stack_size);
}

bool stack_push(int *stack, int data, unsigned int *top_position, unsigned int stack_size) {
    if (*top_position == stack_size)
        return false;
    
    (*top_position)++;
    stack[ *top_position ] = data;
    
    return true;
}

bool stack_pop(int *stack, int *returned_popped_data, 
    unsigned int *top_position) {

    if (*top_position == 0) 
        return false;
    
    *returned_popped_data = stack[*top_position];
    (*top_position)--;
    return true;
}

void stack_print_all(int *stack, unsigned int top_position) {
    unsigned int i = 0;

    printf("here is the stack_a: \n");
    for (i = 0; i <= top_position; i++) {
        printf("\t%d\n", stack[i]);
    }
}

int main()
{
    int stack_a[STACK_SIZE] = {1, 2, 3};
    unsigned int i = 0; 
    unsigned int last_filled_position = 2;

    stack_print_all(stack_a, last_filled_position);

    printf("peeking the stack: %d\n", stack_peek(stack_a, last_filled_position));
    stack_push(stack_a, 56, &last_filled_position, STACK_SIZE);

    stack_print_all(stack_a, last_filled_position);

    printf("pop!");

    int returned_pop;
    stack_pop(stack_a, &returned_pop, &last_filled_position);

    stack_print_all(stack_a, last_filled_position);
    
    return 0;
}