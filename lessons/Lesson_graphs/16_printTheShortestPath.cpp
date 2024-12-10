// Printing the shortest path using dijastra's algo

#include<iostream>
using namespace std;

vector<int> get_the_shortest_path(vector<pair<int, int>> adj[], int source, int n){
    // here n is no of nodes
    vector<pair<int, int>> ans(n, {INT_MAX ,-1});
    vector<int> final_ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    ans[0] = {-1, 0};
    
    while(!pq.empty()){
        int node = pq.top().second;
        int value = pq.top().first;

        for(auto it: adj[node]){
            int new_val = it.second;
            int new_node = it.first;
            int new_dist = new_val + value;

            if(new_dist < ans[new_node].first){
                ans[new_node].first = new_dist;
                ans[new_node].second = node;
            }
        }
    }

    int i = n-1;
    final_ans.push_back(n-1);
    while(ans[i].second != source){
        final_ans.push_back(ans[i].second);
        i = ans[i].second;
    }

    return final_ans;
}