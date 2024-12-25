// toposort
#include<iostream>
using namespace std;

// conditions for toposort
// graph must no be cyclic
// grpah must be directed

void helper(vector<vector<int>>& adj, int node, vector<bool> &isVis, stack<int> &ans){
    isVis[node] = true;
    for(auto i: adj[node]){
        if(!isVis[i]){
            helper(adj, i, isVis, ans);
        }
    }
    ans.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> isVis(n, false);
    vector<int> ans;
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!isVis[i]){
            helper(adj, i, isVis, st);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}