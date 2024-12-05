// Detecing the cycle in Directed Graph
// here the parent is never be in adjacent list for any node

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool dfs(vector<int> adj[], vector<bool> &vis_1, vector<bool> &vis_2, int node){
    vis_1[node] = true;
    
    for(auto it: adj[node]){
        if(vis_1[it] != true) return dfs(adj, vis_1, vis_2, it);
        if(vis_1[it] == true && vis_2[it] == true) return true;
    }

    // comming  back and marking the current node as false
    vis_2[node] = false;
    return false;
}


// moving back and traveliing from another root 
// pointers must be in smae direction for cycle
// reuqire two vectirs for vis and unvis
// we have to ckeck if the visisted are in same path or not
bool is_there_is_cycle_in_loop(vector<int> adj[], int n){
    vector<bool> isVis_1(n , false);
    vector<bool> isVis_2(n , false);

    for(int i=0; i<n; i++){
        if(isVis_1[i]!=true){
            if(dfs(adj, isVis_1, isVis_1, i) == true) return true;
        }
    }
    return false;
}

