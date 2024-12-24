// cycle detection using the dfs algorithm 
#include<iostream>
#include<vector>
using namespace std;

// time complexity o(v + 2E)
// space complexity o(N)
bool helper(vector<vector<int>> &adj, int node, int parent, vector<bool> &isVis){
    isVis[node] = true;
    for(auto i: adj[node]){
        if(i == parent) continue;
        // sometime there is self loop so
        if(node == i) continue;
        if(!isVis[i]){
            if(helper(adj, i, node, isVis) == true) return true; 
        }else{
            return true;
        }
    }
    return false;
}

bool isCycleDetected(vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> isVis(n, false);
    for(int i=0; i<n; i++){
        if(helper(adj, i, -1, isVis) == true){
            return true;
        }
    }
    return false;
}