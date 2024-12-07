//QUESTION - https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int modulo = 1000000000+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long, long>> adj[n];
        // making of adjacent vector contains from - {to1, w1}, {to2, w} ...
        for (auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long> dist(n, LONG_MAX);
        vector<long> ways(n, 0);
        ways[0] = 1;

        // starting from 0 and want ro reach n-1th node
        // the structure of mpq is {distance, node}
        priority_queue<pair<long, long>, vector<pair<long, long>>,
                       greater<pair<long, long>>>
            mpq;
        mpq.push({0, 0});
        dist[0] = 0;
        long count = 0;

        while (!mpq.empty()) {
            long node = mpq.top().second;
            long value = mpq.top().first;
            mpq.pop();


            for (auto it : adj[node]) {
                long new_node = it.first;
                long new_value = it.second + value;
                if (new_value < dist[new_node]) {
                    dist[new_node] = new_value;
                    mpq.push({new_value, new_node});
                    ways[new_node] = ways[node] % modulo;
                } else if (new_value == dist[new_node]) {
                    ways[new_node] += ways[node] % modulo;
                }
            }
        }
        return ways[n-1] % modulo;
    }
};