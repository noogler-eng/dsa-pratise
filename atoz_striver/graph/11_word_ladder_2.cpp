// QUESTION - https://leetcode.com/problems/is-graph-bipartite/

#include<iostream>
#include<vector>
using namespace std;

// any graph can be bipartie if it fllows the rule of change in color
// in every adjacent node
// time complexity o(V + 2E)
// space complexity o(N)
class Solution {
public:
    bool helper(vector<vector<int>>& graph, int node, int parent, int color, vector<int> &colorVector){
        colorVector[node] = color;
        for(auto i: graph[node]){
            if(colorVector[i] == -1){
                if(helper(graph, i, node, !color, colorVector) == false) return false;
            }else{
                if(i == parent) continue;
                else {
                    if(colorVector[i] == colorVector[node]) return false;
                } 
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colorVector(n, -1);
        int color = 1;
        for(int i=0; i<n; i++){
            if(colorVector[i] == -1) 
            if(helper(graph, i, -1, !color, colorVector) == false){
                return false;
            }
        }
        return true;
    }
};