// Bridges in graph
// its and edge whose remove make the graph dissconnected
// means after removal there must be different parents for different nodes
// time[] - when you reach the node for first time
// low[] - minimum time of insertion around all its adjacent node apart from parent

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int tin[100005], low[100005];
int isVis[100005];
int timer = 0;
void bridge_nodes(vector<int> adj[], int node, int parent){
    tin[node] = low[node] = timer++;
    isVis[node] = 1;
    for(auto it: adj[node]){
        if(it == parent) continue;
        if(isVis[node] != 1){
            bridge_nodes(adj, it, node);
            // taking from adajacen one 
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node]){
                cout<<"bridge between: "<<node<<" -> "<<it<<endl;
            }
        }else{
            low[node] = min(low[node], tin[it]);
        }
    }
}