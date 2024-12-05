// Detect the odd length cycle
// 1 - 2 - 3 - 4 - 5 - 6 - 7 - 3

// Bipartitie graph -> coloring the graph with two diff color
// none of the color is adjacent then it is bipartite graph

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// if it is bypartitie cyclic graph then it is even
// if it is non bypartitie cyclic graph then odd

// here we are simply checking if the graph is bipartite or not
int col[10005];
bool check_for_bipartitie(vector<int> adj[], int node, int color){
    col[node] = color;
    for(auto it: adj[node]){
        if(col[it] == -1){
            // it means the it is unvisited
            if(check_for_bipartitie(adj, it, !color)){
                return true;
            }
        }else if(col[it] == color){
            // when it comes here means this node is aready vistsed
            // smae color with the current node means adj having same color
            return true;
        }
    }
    return false;
}