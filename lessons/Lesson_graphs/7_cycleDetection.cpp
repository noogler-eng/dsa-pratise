// cycle detection in both directed and undirected graph
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// same logic in BFS and DFS
bool dfs(vector<int> adj[], vector<bool> &isVis, int i, int parent){
    isVis[i] = true;
    for(auto it: adj[i]){
        // remeber not to be matching with where it is comming from 
        if(it != parent){
            if(isVis[it] == false){
                return dfs(adj, isVis, it, i);
            }else{
                // it means the parent is not checking here
                // other nodes are checking, if any of them is already visited then return true
                return true;
            }
        }
    }
    return false;
}

// we are using dfs to detect wheather we reached previously visited node
// in multiple diff component we run a dfs
// n is the number of nodes
bool is_there_is_cycle(vector<int> adj[], int n){
    vector<bool> isVis(n+1);

    // on the starting node there must be no parent so marking it as -1
    for(int i=0; i<n; i++){
        if(isVis[i] != true){
            if(dfs(adj, isVis, i, -1) == true) return true;
        }
    }
    return false;
}   
