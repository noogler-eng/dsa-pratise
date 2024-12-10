// dfs -> depth first search
#include<iostream>
#include<vector>
using namespace std;

// moving the dfs of the graph
// time complexity o(N) + o(2M)
void dfs(vector<int> adj[], vector<bool> &isVis, int n){
    cout<<n<<" ";
    isVis[n] = 1;
    for(auto i: adj[n]) if(isVis[i] == false) dfs(adj, isVis, i);
    return;
}

int main(){
    // no of nodes
    int n;
    vector<int> adj[5];
    vector<bool> isVis(n, false);

    // traversing all the nodes
    for(int i=0; i<n; i++) if(isVis[i] == false) dfs(adj, isVis, i);
    return 0;
}
