// TopoSort - linear ordering of the vertices / node such that u -> v then
// u comes first then v in ordering
// toposort is possible in DAG(directed acyclic graph)

// two ways to do toposort
// 1. DFS (vector and stack require)
// 2. KHAN's algorithm (BFS)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// time complexity o(N), travelling every node of the graph
void topo_helper(vector<int> adj[], vector<bool> &vis, int node, stack<int> &st){
    vis[node] = true;
    for(auto it: adj[node]){
        if(!vis[it]){
            topo_helper(adj, vis, it, st);
        }
    }
    st.push(node);
}

// it returns the vectors in order of the topo sort
vector<int> topo_sort(vector<int> adj[], int n){
    stack<int> st;
    vector<int> ans;
    vector<bool> vis(n+1, false);
    for(int i=0; i<n; i++){
        if(vis[i] == false) topo_helper(adj, vis, i, st);
    }   

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}