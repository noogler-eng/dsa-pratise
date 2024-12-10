// DSU - (disjoint set union)
// path compression 
// union by rank
// union by size

// DSU - 
// it is used in finding wheather two nodes belong to same conponent or not
// making parent of each element itself,
// after this two node belong to same element if their root parent are same
// if we do simple union then skew tree will be formed - more time consuming

// path compression
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class DSU{
    public:
    vector<int> parent, size;
    // making everynode parent of itself
    // making size of each node to be 1
    DSU(int n){
        for(int i=0; i<n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }

    // finding the parent of the component
    // each component has a single main parent
    // here path compression is done here
    int find_parent(int node){
        if(parent[node] == node) return node;
        return parent[node] = find_parent(node);
    }

    // joining two componennts if they are diff
    // if not then simply return;
    void do_union(int u, int v){
        int pu = parent[u];
        int pv = parent[v];
        if(pu == pv) return;
        else {
            if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    }
};



