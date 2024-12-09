// BellmanFord ALgo
// if there is negative edges then dijkasta not works
// Bellam ford will work for negative edges

// in dijkstra we added the distance then it will be minimum then the travell back to prev
// but in -ve cycle on previos traversal it becomes more premium.
// dijakstra is an algo take o(nlogn).
// bellman ford take (n*n)

// in -ve edges dijkasta ends up in infinity cycle.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Edges {
    public:
        int u;
        int v;
        int weight;
        Edges(int u, int v, int weight){
            this->u = u;
            this->v = v;
            this->weight = weight;
        }
};

// used to finding the closest distance from source node 
// also work for negative weight case also
// time complexity o((N-1)*N)
vector<int> bellman_ford_algoritm(vector<Edges> conn, int n){
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    for(int i=0; i<n-1; i++){
        for(auto it: conn){
            int u = it.u;
            int v = it.v;
            int weight = it.weight;
            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }

    // it is is cycle then source distance will change on last to fist connection
    // making the condition to be true then return vector[]
    for(auto it: conn){
        int u = it.u;
        int v = it.v;
        int weight = it.weight;
        if(dist[u] + weight < dist[v]){
            dist[v] = dist[u] + weight;
            cout<<"exits a cycle"<<endl;
            vector<int> ans;
            return ans;
        }
    }

    return dist;
}

