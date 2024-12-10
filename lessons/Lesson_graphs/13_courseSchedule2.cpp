// QUESTION - https://leetcode.com/problems/course-schedule-ii/
// topo-sort - both checking and arranging on topo order

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool isCyclic(vector<int> adj[], vector<bool> &vis, vector<bool> &visPath, int node){
        vis[node] = true;
        visPath[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(isCyclic(adj, vis, visPath, it)) return true;
            }else if(vis[it] && visPath[it]){
                return true;
            }
        }
        visPath[node] = false;
        return false;
    }


    void dfs(vector<int> adj[], stack<int> &st, vector<bool> &vis, int node){
        vis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj, st, vis, it);
            }
        }
        st.push(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<bool> vis(numCourses, false);
        vector<bool> vis_1(numCourses, false);
        vector<bool> vis_2(numCourses, false);
        vector<int> ans;
        stack<int> st;
        for(auto i: prerequisites) adj[i[1]].push_back(i[0]);

        // first checking if there is cycle or not
        for(int i=0; i<numCourses; i++){
            if(!vis_1[i]){
                if(isCyclic(adj, vis_1, vis_2, i) == true) return ans;
            }
        }

        // making the topo-sorting order
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                dfs(adj, st, vis, i);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};