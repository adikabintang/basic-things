## Graph

### Terms
- Vertex: the point
- Edge: the line
- Adjacency: the neighboring vertices
- Path: the path it takes from one vertex to another
- Degree of the vertex: the number of edges incident on a vertex
- Cycle: when a path goes from a particular vertex back to itself
- Weighted graph: graph with weight on the edges
- Undirected graph: the edge has no direction
- Directed graph: the edges are directed
- Directed acyclic graph (dag): the directed graph with no cycle
- Out-degree: the number of edges leaving a vertex
- In-degree: the number of edges entering a vertex

### Representing graphs
A very simple example of a graph that will be used for this case study:
```
0 -- 1
|    | 
|    |
2    3
```
#### Edge lists
Edge lists use the array of the edges represented by the vertices.

Example:
```
int edge_list[2][2] = {{0, 1}, {0, 2}, {1, 3}}; 
```

If we need to add the wheigh, just add it as the third element.

**Problem**: Need linear search if we want to find a particular edge.

#### Adjacency matrices 
It is a |V| x |V| matrix with 0 and 1 representing is there any vertex on that point (i, j). The matrix:
```
    0  1  2  3
---------------
0 | 0  1  1  0
1 | 0  0  0  1
2 | 0  0  0  0
3 | 0  0  0  0
```
The array can be made as the following:
```
int adjacency_matrices[4][4] = 
    {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
```

The edge list's problem in finding the edge does not appear here as we can just check whether the edge (i, j) is present on the `array[i][j]`.

**Problems**:
- It needs more space. It takes Θ(V^2).
- If we want to find out which vertices are adjacent to a given vertex i, we have to look at all |V| entries in row i.

#### Adjacency lists
For each vertex i, store an array of the vertices adjacent to it.
Visually, it looks like this:
```
0 -> 1, 2
1 -> 3
```
In array form:
```
int adjacency_list[2][2] = 
    {
        {1, 2},
        {3}
    };
```

To find out wheter the edge (i, j) is present, the worst case time is Θ(d), where d is the degree of the vertex i.

The space needed is at most `2 * number of edges`.

### Depth First Traversal
https://www.tutorialspoint.com/data_structures_algorithms/depth_first_traversal.htm