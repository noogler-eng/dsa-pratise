// QUESTION - https://leetcode.com/problems/network-delay-time/?envType=problem-list-v2&envId=9id5lube

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    // times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mq;
        mq.push({0, k});

        while(!mq.empty()){
            int current_time = mq.top().first;
            int current_node = mq.top().second;
            mq.pop();

            for(auto it: adj[current_node]){
                int new_time = it.second;
                int new_node = it.first;

                if(current_time + new_time < dist[new_node]){
                    dist[new_node] = current_time + new_time;
                    mq.push({current_time + new_time, new_node});
                }

            }
        }

        int mini = INT_MIN;
        for(int i=1; i<dist.size(); i++){
            if(dist[i] == INT_MAX) return -1;
            mini = max(mini, dist[i]);
        }

        return mini;
    }
};