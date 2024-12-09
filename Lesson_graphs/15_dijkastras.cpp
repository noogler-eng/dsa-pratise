// here weights are variables on the edges
// we have to find the minimum distance from the source node, use priority queue or set
// dijstra algo will not work for negative cycles / neative wieight edges
// for negatice cycles we will stuck in loop

#include<iostream>
#include <queue>
#include<vector>
using namespace std;

vector<int> minimum_distance_of_nodes_from_source_node(vector<pair<int, int>> adj[], int source, int n){
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mq;

    // prioirtiy queue works on first element in pair, sort acc to that
    // time complexity o(nlogn) + e = nlog(n)
    // traversing each edges and each node, for inserting log(n)
    mq.push({0, source});
    dist[source] = 0;
    while(!mq.empty()){
        int node = mq.top().second;
        int value = mq.top().first;
        mq.pop();

        for(auto it: adj[node]){
            int new_node = it.first; 
            int addon = it.second;
            // making the new distance 
            int new_dist = addon + value;
            // checking if the distance is smaller then taking that route and moving in that direction
            if(new_dist < dist[new_node]){
                dist[new_node] = new_dist;
                mq.push({new_dist, new_node});
            }
        }
    }
    return dist;
}