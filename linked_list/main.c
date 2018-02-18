#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    int key;
    struct node *next;
};

int get_list_length(struct node *the_head)
{
    struct node *current = the_head;
    int length = 0;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

void print_list(struct node *head)
{
    struct node *current = head;

    while (current != NULL)
    {
        printf("key: %d, data: %d\n", current->key, current->data);
        current = current->next;
    }
}

// push node OR insert at first
void push_new_node(struct node **head, int key, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->key = key;
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_nth_node(struct node **head, unsigned int position, int key, int data)
{
    struct node *new_node;
    struct node *current;
    struct node *before = current;
    unsigned int i = 0;

    if (*head == NULL)
    {
        push_new_node(head, key, data);
    }
    else
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        current = *head;
        before = current;
        new_node->key = key;
        new_node->data = data;

        for (i = 0; i < position; i++)
        {
            before = current;
            current = current->next;
        }

        before->next = new_node;
        new_node->next = current;
    }
}

// OR delete first
void delete_top_node(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_nth_node(struct node **head, unsigned int position)
{
    struct node *current = *head;
    struct node *before = current;
    unsigned int i = 0;

    if (position == 0)
    {
        *head = (*head)->next;
    }
    else
    {
        for (i = 0; i < position; i++)
        {
            before = current;
            current = current->next;
        }

        before->next = current->next;
    }

    free(current);
}

bool is_list_empty(struct node **head)
{
    return *head == NULL;
}

struct node *find_node(struct node **head, int key)
{
    struct node *current = *head;

    while (current != NULL)
    {
        if (current->key == key)
        {
            break;
        }

        current = current->next;
    }

    return current;
}

int main()
{
    struct node *head = NULL;
    struct node *current = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    head->key = 0;
    head->data = 12;
    head->next = NULL;
    current = head;

    push_new_node(&head, 1, 13);
    push_new_node(&head, 2, 14);
    push_new_node(&head, 3, 15);
    push_new_node(&head, 4, 16);
    push_new_node(&head, 5, 17);

    printf("before delete on top:\n");
    print_list(head);

    insert_nth_node(&head, 1, 123, 123);
    printf("after inserting nth node:\n");
    print_list(head);

    delete_top_node(&head);
    printf("\nafter delete on top:\n");
    print_list(head);

    delete_nth_node(&head, 2);
    printf("\nafter delete nth position:\n");
    print_list(head);

    printf("the length: %d\n", get_list_length(head));

    struct node *temp = find_node(&head, 12);
    if (temp != NULL)
    {
        printf("Found -> data: %d\n", temp->data);
    }
    else
    {
        printf("not found\n");
    }

    return 0;
}