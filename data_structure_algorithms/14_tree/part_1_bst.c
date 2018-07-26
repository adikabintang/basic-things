#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left_child;
    struct node *right_child;
};

struct node *root = NULL;

void bt_insert(int data) {
    struct node *inserted_node = (struct node *)malloc(sizeof(struct node));
    struct node *current;
    struct node *parrent;

    inserted_node->data = data;
    inserted_node->left_child = NULL;
    inserted_node->right_child = NULL;

    if (root == NULL) {
        root = inserted_node;
    } else {
        current = root;
        while (1) {
            parrent = current;
            if (data >= current->data) {
                current = current->right_child;
                if (current == NULL) {
                    current = inserted_node;
                    parrent->right_child = current;
                    return;
                }
            } else {
                current = current->left_child;
                if (current == NULL) {
                    current = inserted_node;
                    parrent->left_child = current;
                    return;
                }
            }
        }
    }
}

struct node *bt_search(int data) {
    struct node *current = root;

    while (current != NULL) {
        if (data == current->data) {
            return current;
        } else if (data > current->data) {
            current = current->right_child;
        } else {
            current = current->left_child;
        }
    }

    return NULL;
}

// in-order traversal: left to right; sorted from the lowest value to the highest
/*
Until all nodes are traversed −
Step 1 − Recursively traverse left subtree.
Step 2 − Visit root node.
Step 3 − Recursively traverse right subtree.
*/
void bt_in_order_traversal(struct node *the_node) {
    if (the_node != NULL) {
        bt_in_order_traversal(the_node->left_child);
        printf("%d ", the_node->data);
        bt_in_order_traversal(the_node->right_child);
    }
}

// pre-order traversal: root, left, then right
/*
Until all nodes are traversed −
Step 1 − Visit root node.
Step 2 − Recursively traverse left subtree.
Step 3 − Recursively traverse right subtree.
*/
void bt_pre_order_traversal(struct node *the_root) {
    if (the_root != NULL) {
        printf("%d ", the_root->data);
        bt_in_order_traversal(the_root->left_child);
        bt_in_order_traversal(the_root->right_child);
    }
}

// post-order: left, right, root
/*
Until all nodes are traversed −
Step 1 − Recursively traverse left subtree.
Step 2 − Recursively traverse right subtree.
Step 3 − Visit root node.
*/
void bt_post_order_traveral(struct node *the_root) {
    if (the_root != NULL) {
        bt_in_order_traversal(the_root->left_child);  
        bt_in_order_traversal(the_root->right_child);
        printf("%d ", the_root->data);
    } 
}

int main() {
    bt_insert(1);
    bt_insert(0);
    bt_insert(5);

    struct node *find_node = bt_search(5);
    if (find_node == NULL) {
        printf("node not found\n");
    } else {
        printf("node found\n");
    }

    printf("in order: ");
    bt_in_order_traversal(root);
    printf("\npre-order: ");
    bt_pre_order_traversal(root);
    printf("\npost-order: ");
    bt_post_order_traveral(root);

    return 0;
}