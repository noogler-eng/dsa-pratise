// BFS traversal in the graph
// time complexity o(v + 2E)
// space complexity o(2N)
#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>> &adj, int node, vector<bool> &isVis, vector<int> &ans){
    isVis[node] = true;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(auto i: adj[x]){
            if(!isVis[i]) {
                q.push(i);
                isVis[i] = true;
            }
        }
    }
}

vector<int> bfsOfGraph(vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> isVis(n, false);
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(!isVis[i]) helper(adj, i, isVis, ans);
    }
    return ans;
}