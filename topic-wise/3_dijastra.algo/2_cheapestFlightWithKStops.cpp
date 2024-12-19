// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=problem-list-v2&envId=9id5lube
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        // making of an adjacent matrix
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        for (int i = 0; i < flights.size(); i++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            // directed graph
            adj[from].push_back({to, price});
        }

        // at most k stops
        // distance, level, node
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            mq;
        mq.push({0, {0, src}});
        while (!mq.empty()) {
            int current_price = mq.top().first;
            int current_level = mq.top().second.first;
            int current_node = mq.top().second.second;
            mq.pop();

            if (current_node == dst) {
                return current_price;
            }

            if(current_level < k+1){
                for (auto it : adj[current_node]) {
                    int new_node = it.first;
                    int addon_price = it.second;
                    if (current_price + addon_price < dist[new_node][current_level]) {
                        dist[new_node][current_level] = current_price + addon_price;
                        mq.push({current_price + addon_price,
                                {current_level + 1, new_node}});
                    }
                }
            }
        }

        return dist[dst][k] == INT_MAX ? -1 : dist[dst][k];
    }
};