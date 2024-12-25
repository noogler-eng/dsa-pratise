// QUESTION - https://leetcode.com/problems/course-schedule-ii/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void helper2(vector<vector<int>>& adj, int node, stack<int> &ans, vector<bool> &isVis){
        isVis[node] = true;
        for(auto i: adj[node]){
            if(!isVis[i]) helper2(adj, i, ans, isVis);
        }
        ans.push(node);
    }

    void topoSort(vector<vector<int>> adj, vector<int> &ans, int n){
        vector<bool> isVis(n, false);
        stack<int> st;
        for(int i=0; i<n; i++){
            if(!isVis[i]) helper2(adj, i, st, isVis);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    }

    bool helper1(vector<vector<int>>& adj, int node, vector<bool> &isVis_1, vector<bool> &isVis_2){
        isVis_1[node] = true;
        isVis_2[node] = true;
        for(auto i: adj[node]){
            if(isVis_1[i] == true && isVis_2[i] == true){
                return true;
            } 
            if(isVis_1[i] != true){
                if(helper1(adj, i, isVis_1, isVis_2) == true) return true;
            }
        }
        isVis_2[node] = false;
        return false;
    }

    bool isCyclic(vector<vector<int>>& adj, int n){
        vector<bool> isVis_1(n, false);
        vector<bool> isVis_2(n, false);
        for(int i=0; i<n; i++){
            if(!isVis_1[i]) {
                if(helper1(adj, i, isVis_1, isVis_2) == true) return true;
            }
        }
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // firstly making an adj list
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> ans;
        // first checking if there is cycle or not (using DfS)
        if(isCyclic(adj, numCourses) == true) return ans;
        cout<<"reached"<<endl;

        // toposort (using DFS)
        topoSort(adj, ans, numCourses);
        return ans;
    }
};