// QUESTION - https://leetcode.com/problems/course-schedule/
// simply if we detect the cycle in graph then it can never be converted into toposort
// condition for totposort -> DAG(directed acyclic graph)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis, int node, int parent){
        vis[node] = true;
        pathVis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]) {
                if(dfs(adj, vis, pathVis, it, node)) {
                    return true;
                }
            }
            else if(vis[it] && pathVis[it]) return true;
        }
        pathVis[node] = false;
        return false;
    }


    bool isCyclic(vector<int> adj[], int n){
        vector<bool> vis(n+1, false);
        vector<bool> pathVis(n+1, false);
        for(int i=0; i<n; i++) if(!vis[i]) if(dfs(adj, vis, pathVis, i, -1)) return true;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;
        
        // making of adjacent matrix
        vector<int> adj[numCourses];
        for(auto i: prerequisites) adj[i[1]].push_back(i[0]);
        return !isCyclic(adj, numCourses);
    }
};