#include <stdio.h>

#define ARRAY_SIZE 8

// will return -1 if not found, else return index number
int ls_search(int *array, int searched_data, unsigned int array_size)
{
    unsigned int i = 0;

    for (i = 0; i < array_size; i++)
    {
        if (array[i] == searched_data)
            return i;
    }

    return -1;
}

int main()
{
    int my_array[ARRAY_SIZE];
    unsigned int i = 0;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        my_array[i] = i + 2;
    }

    int index = ls_search(my_array, 3, ARRAY_SIZE);
    if (index == -1)
    {
        printf("not found\n");
    }
    else
    {
        printf("found at: %d\n", index);
    }

    return 0;
}