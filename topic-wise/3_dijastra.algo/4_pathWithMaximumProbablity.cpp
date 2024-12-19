// QUESTION - https://leetcode.com/problems/path-with-maximum-probability/description/?envType=problem-list-v2&envId=9id5lube

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // making an array for adjacent nodes
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double success = succProb[i];
            adj[u].push_back({v, success});
            adj[v].push_back({u, success});
        }

        priority_queue<pair<double, int>> mq;
        vector<double> fp(n, 0.0);
        fp[start_node] = 1.0;

        mq.push({1.0, start_node});
        while(!mq.empty()){
            int current_node = mq.top().second;
            double current_probab = mq.top().first;
            mq.pop();

            if(current_node == end_node) {
                return current_probab;
            };

            for(auto it: adj[current_node]){
                int new_node = it.first;
                double new_probab = it.second;
                if(new_probab * current_probab > fp[new_node]){
                    fp[new_node] = new_probab * current_probab;
                    mq.push({new_probab * current_probab, new_node});
                }
            }
        }

        return 0;

    }
};