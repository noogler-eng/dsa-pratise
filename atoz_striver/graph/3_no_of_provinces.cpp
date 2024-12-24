// QUESTION - https://leetcode.com/problems/number-of-provinces/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    void helper(vector<vector<int>> adj, int node, vector<bool> &isVis){
        isVis[node] = true;
        for(auto i: adj[node]){
            if(!isVis[i]){
                helper(adj, i, isVis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> isVis(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!isVis[i]) {
                helper(adj, i, isVis);
                count++;
            }
        }

        return count;
    }
};