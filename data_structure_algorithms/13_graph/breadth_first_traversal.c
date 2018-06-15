#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5

struct vertex {
    char label;
    bool visited;
};

// queue variables
int queue[MAX];
int rear = -1;
int front = 0;
int queue_item_count = 0;

// graph variables

// array of vertices
struct vertex *list_of_vertices[MAX];

// adjacency matrix
int adj_matrix[MAX][MAX] = { { 0 } };

// vertex count
int vertex_count = 0;

// queue functions
void queue_insert(int vertex_index_as_data) {
    queue[++rear] = vertex_index_as_data;
    queue_item_count++;
}

int queue_remove_data() {
    queue_item_count--;
    return queue[front++]; // return the front in queue before it is deleted
}

bool queue_is_empty() {
    return (queue_item_count == 0);
}

// graph functions

// add vertex to the list
void add_vertex(char label) {
    struct vertex *v = (struct vertex *) malloc(sizeof(struct vertex));
    v->label = label;
    v->visited = false;
    list_of_vertices[vertex_count++] = v;
}

// add edge to the edge array 
void add_edge(int start, int end) {
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1;    
}

// display the vertex 
void display_vertex(int vertex_index) {
    printf("%c ", list_of_vertices[vertex_index]->label);
}

// get the adjacent unvisited vertex
int get_adjacent_unvisited_vertex(int vertex_index) {
    int i;

    for (i = 0; i < vertex_count; i++) {
        if (adj_matrix[vertex_index][i] == 1 && list_of_vertices[i]->visited == false) {
            return i;
        }
    }

    return -1;
}

void breadth_first_search() {
    int i, unvisited_vertex, temp_vertex;

    // mark the first node as visited
    list_of_vertices[0]->visited = true;

    // insert vertex ini queue 
    queue_insert(0);
    display_vertex(unvisited_vertex);
            
    while (!queue_is_empty()) {
        // get the unvisited vertex of vertex which is at front of the queue
        temp_vertex = queue_remove_data();
    
        unvisited_vertex = get_adjacent_unvisited_vertex(temp_vertex);
        // no adjacent vertex found
        while (unvisited_vertex != -1) {
            display_vertex(unvisited_vertex);
            list_of_vertices[unvisited_vertex]->visited = true;
            queue_insert(unvisited_vertex);
            unvisited_vertex = get_adjacent_unvisited_vertex(temp_vertex);
        }
    }

    printf("\n");

    //queue is empty, search is complete, reset the visited flag  
    for (i = 0; i < vertex_count; i++) {
        list_of_vertices[i]->visited = false;
    }
}

int main() {
    int i, j;

    add_vertex('S');   // 0
    add_vertex('A');   // 1
    add_vertex('B');   // 2
    add_vertex('C');   // 3
    add_vertex('D');   // 4

    add_edge(0, 1);    // S - A
    add_edge(0, 2);    // S - B
    add_edge(0, 3);    // S - C
    add_edge(1, 4);    // A - D
    add_edge(2, 4);    // B - D
    add_edge(3, 4);    // C - D

    printf("\nBreadth First Search: ");
   
    breadth_first_search();

    return 0;
}