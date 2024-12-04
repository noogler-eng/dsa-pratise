// bfs -> bredth first search
#include<iostream>
#include<queue>
using namespace std;

// time complexity o(N)
// space complexity o(N)
void bfs(vector<int> adj[], vector<bool> isVis, int node){
    queue<int> q;
    q.push(node);
    isVis[node] = 1;

    while(!q.empty()){
        int n = q.front();
        q.pop();
        cout<<n<<" ";
        for(auto it: adj[n]){
            if(isVis[it] == false) {
                isVis[it] = 1;
                q.push(it);
            }
        }
    }
    return;
}



int main(){
    // no of nodes
    int n;
    vector<int> adj[5];
    vector<bool> isVis(n, false);

    // traversing all the nodes
    for(int i=0; i<n; i++) if(isVis[i] == false) bfs(adj, isVis, i);
    return 0;
}