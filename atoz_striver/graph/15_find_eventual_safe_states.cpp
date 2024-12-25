// QUESTION - https://leetcode.com/problems/find-eventual-safe-states/description/
// important question

#include<iostream>
#include<vector>
using namespace std;

// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

// we can solve this using DFS and BFS
// safe node -> every path from that node should be ends up at the terminal node
// all the path should be ended at something or formed a loop means return back themselves, any node who is the part of the cycle is not count
// anyone who is the part of the cycle or leads to the cycle - reject


class Solution {
public:
    bool helper(vector<vector<int>>& graph, int node, vector<int> &vis, vector<int> &pathVis, vector<int> &check){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto i: graph[node]){
            if(!vis[i]){
                // if there is a cycle then it will already break here
                if(helper(graph, i, vis, pathVis, check) == 1) return true;
            }else if(vis[i] && pathVis[i]){
                return true;
            }
        }
        // if there is a cycle then it will never reach here due to halway recurssion every-time
        // this is only changed part, as all this nodes will not involve in cycle
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n, 0);
        vector<int> safeNode;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                helper(graph, i, vis, pathVis, check);
            }
        }

        for(int i=0; i<n; i++){
            if(check[i] == 1){
                safeNode.push_back(i);
            }
        }
        return safeNode;
    }
};