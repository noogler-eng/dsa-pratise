// DFS traversal in the graph
// time complexity o(v + 2E)
// space complexity o(2N)
#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>> &adj, int node, vector<bool> &isVis, vector<int> &ans){
    isVis[node] = true;
    ans.push_back(node);
    for(auto i: adj[node]){
        if(!isVis[i]) helper(adj, i, isVis, ans);
    }
}

vector<int> dfsOfGraph(vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> isVis(n, false);
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(!isVis[i]) helper(adj, i, isVis, ans);
    }
    return ans;
}