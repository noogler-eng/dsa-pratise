// 0/1 BFS 
// graph having the weights 0 and 1
// in this we have to find the distance from source node to other nodes
// source node is starting node

// using dq
// placing the minimum distance in front and more distance from back in dq
// whenever we add 0 push in front or whenever we add +1 push in back
// in dq increasing distance is happening

#include<iostream>
#include<deque>
using namespace std;

// time complexity o(N)
// it will be applicable for only 2 weights and in which one weight must be 0
// another one weight must be any number
vector<int> minimun_distance_from_source_node(vector<pair<int, int>> adj[], int start, int n){
    deque<pair<int, int>> dq;
    // supposing there is n nodes
    vector<int> miniVDist(n, INT_MAX);

    dq.push_back({start, 0});
    while(!dq.empty()){
        int front_node = dq.front().first;
        int value = dq.front().second;
        dq.pop_front();

        for(auto it: adj[front_node]){
            int newValue = value + it.first;
            // only add when distance changes
            if(miniVDist[it.first] > newValue){
                if(it.second == 1) dq.push_back({it.first, newValue});
                else dq.push_front({it.first, newValue});
                miniVDist[it.first] = newValue;
            }
        }
    }
    return miniVDist;
}