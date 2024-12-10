// Toposort using khan algorithm
// indegree -> the number of degree comming inside to the node
// as a fact -> total indegree and outdegree of the graph is always 0
// concept of zero indegree will be used

#include<iostream>
#include<vector>
using namespace std;

vector<int> topo_sort(vector<int> adj[], int n){
    vector<int> indegree(n, 0);
    vector<int> ans;
    queue<int> q;
    for(int i=0; i<n; i++){
        for(auto node: adj[i]){
            // inserting the indegree's
            indegree[node]++;
        }
    }

    for(int i=0; i<n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
        ans.push_back(node);
    }

    return ans;
}
