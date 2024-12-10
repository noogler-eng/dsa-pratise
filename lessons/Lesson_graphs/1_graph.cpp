// Graphs and its representation
// Traversal Techniques (BFS, DFS)
// Cycle Detection Technique
// Island Problems

// Google map is primary example

// node and edges
// graph may be connected or may not
// directed and undirected graph
// wieghted and unweighted graph
// the unconnected graphs having components but whole is single graph

// properties
// if there are n nodes then there will be n-1 edges in trees but in graph it is not necessary.
// 2D matrix is adjacency matrix
// 1 - 2 - 3 - 4 - 1
// adj matrix -> n(node), m(edges)
// m * n -> [{1, 2}, {2, 3}, {1, 4}, {3, 4}], m lines

// adj matrix -> binary matrix edge between node make it 1 otherwise 0
// (n+1)*(m+1) matrix formed ....
// vector<int> arr[5], array of 5 where at each index vector is stored
// 1 - 2 - 3 - 4 - 1
// then on arr[1] = 2, 4
// then on arr[2] = 3, 1
// then on arr[3] = 2, 4
// ...

// store the weighted graph by the pairs
// vector<pair<int, int>> arr[5];

// traversal - 
// Depth first search
// travelling to the deep first 

// Breadth first search
// travelling to the nearby of element then movieng of that element nearby
