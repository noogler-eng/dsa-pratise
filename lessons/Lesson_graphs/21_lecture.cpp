// MST 
// Krushkal algo or prim's algo
// Bridges in graph
// Belman ford
// Alien Dictionary (toposort)

// minimum spanning tree
// remove the extra edges from the graph
// from graph to tree then tree must have n-1 edges and n nodes
// spanning tree is we have a an edges to reach all the nodes minimum edges.
// converting graph into tree such that there is no loop

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public: 
    int u;
    int v;
    int weight;
    Node(int u, int v, int weight){
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};

class DSU {
    public:
    vector<int> parent, size;
    DSU(int n){
        for(int i=0; i<n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }

    void join_parent(int node1, int node2){
        if(parent[node1] == parent[node2]) return;
        else{
            if(size[node1] > size[node2]){
                size[node1] += size[node2];
                parent[node2] = node1;
            }else{
                size[node2] += size[node1];
                parent[node1] = node2;
            }
        }
    }

    int find_parent(int node){
        if(parent[node] == node) return node;
        return parent[node] = find_parent(node);
    }
};

// krushkal_algorithm
// sort them corresponding to their weights
// apply dsu, if parents are same then dont connect them otherwise connect them
// if parent are same and we are connecting them then its gaurantee they are in loop
// mst does't contains any loop
int minimum_spanning_tree_cost(vector<Node> &edges, int n){
    sort(edges.begin(), edges.end(), [](Node x, Node y){    
        return x.weight < y.weight;
    });
    
    // here n is no of nodes
    // we have to select n-1 edges
    DSU dsu(n);
    int minCost = 0;
    for(auto it: edges){
        int u = it.u;
        int v = it.v;
        int weight = it.weight;
        if(dsu.find_parent(u) != dsu.find_parent(v)){
            dsu.join_parent(u, v);
            minCost+=weight;
        }
    }

    return minCost;
}