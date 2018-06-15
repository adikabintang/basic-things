/*
* From here: https://www.tutorialspoint.com/data_structures_algorithms/depth_first_traversal_in_c.htm
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5

struct vertex {
    char label;
    bool visited;
};

// stack variables
int stack[MAX];
int top = -1;

// array of vertices
struct vertex *list_of_vertices[MAX];

// adjacency matrix
int adjacency_matrix[MAX][MAX] = { { 0 } };

int vertex_count = 0;

// stack functions
void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

bool is_stack_empty() {
    return (top == -1);
}

// graph functions
void add_vertex(char label) {
    struct vertex *a_vertex = (struct vertex *) malloc(sizeof(struct vertex));
    a_vertex->label = label;
    a_vertex->visited = false;
    list_of_vertices[vertex_count++] = a_vertex;
}

void add_edge(int start, int end) {
    adjacency_matrix[start][end] = 1;
    adjacency_matrix[end][start] = 1;
}

void display_vertex(int vertex_index) {
    printf("%c", list_of_vertices[vertex_index]->label);
}

// get the adjacent unvisited vertex
int get_adj_unvisited_vertex(int vertex_index) {
    int i;

    for (i = 0; i < vertex_count; i++) {
        if (adjacency_matrix[vertex_index][i] == 1 && list_of_vertices[i]->visited == false) {
            return i;
        }
    }
    
    return -1;
}

void depth_first_search() {
    int i, unvisited_vertex;

    // mark the first node as visited
    list_of_vertices[0]->visited = true;

    // display the vertex
    display_vertex(0);

    // push vertex index in stack
    push(0);

    while (!is_stack_empty()) {
        // get the unvisited vertex of vertex which is at the top of the stack
        unvisited_vertex = get_adj_unvisited_vertex(peek());

        // no adjacent vertex found
        if (unvisited_vertex == -1) {
            pop();
        } else {
            list_of_vertices[unvisited_vertex]->visited = true;
            display_vertex(unvisited_vertex);
            push(unvisited_vertex);
        }
    }
}

int main() {
    int i, j;

    add_vertex('S');   // 0
    add_vertex('A');   // 1
    add_vertex('B');   // 2

    add_edge(0, 1);    // S - A
    add_edge(0, 2);    // S - B

    printf("Depth First Search: ");
    depth_first_search(); 

    return 0;
}