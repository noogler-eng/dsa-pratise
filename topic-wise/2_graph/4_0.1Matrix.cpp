// QUESTION - https://leetcode.com/problems/01-matrix/description/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// we are applying bfs on 0 instead of 1
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // for 0 it will remain 0
        // for 1 it will move (bfs), level wise
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && ans[new_x][new_y] == INT_MAX){
                    ans[new_x][new_y] = ans[x][y] + 1;
                    q.push({new_x, new_y});
                }
            }
        }

        return ans;
    }
};