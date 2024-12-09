// QUESTION - https://leetcode.com/problems/number-of-provinces/description/

#include<iostream>
#include<vector>
using namespace std;


// time complexity o(N*N)
// space complexity o(N*N)
class Solution {
public:
    // time complexity o(N)
    void dfs(vector<vector<int>> adj, vector<bool> &isVis, int node){
        isVis[node] = true;
        for(auto it: adj[node]){
            if(!isVis[it]){
                dfs(adj, isVis, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        vector<bool> isVis(n, false);
        // time complexity o(N*N)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // time complexity o(N)
        int count = 0;
        for(int i=0; i<n; i++){
            if(!isVis[i]){
                dfs(adj, isVis, i);
                count++;
            }
        }

        return count;
    }
};