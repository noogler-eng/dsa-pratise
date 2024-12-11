// QUESTION - https://leetcode.com/problems/is-graph-bipartite/

#include<iostream>
#include<vector>
using namespace std;

// for bipartite graph color must be not be same on adj node
// there is no necessaity of loop
class Solution {
public:
    bool helper(vector<vector<int>>& graph, int node, int color,
                vector<int>& col) {
        col[node] = color;
        for (auto it : graph[node]) {
            if (col[it] == -1) {
                 if(helper(graph, it, !color, col) == false) return false;
            } else if (col[it] == color && it != node) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color = 1;
        vector<int> col(n, -1);
        for (int i = 0; i < n; i++) {
            if (col[i] == -1) {
                if (helper(graph, i, color, col) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};