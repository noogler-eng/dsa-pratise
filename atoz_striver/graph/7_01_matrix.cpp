// QUESTION - https://leetcode.com/problems/01-matrix/
// in this question our point of view is 0 instead of the 1
// appying bfs on the 0 instead of the 1

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    // retuning the distnce of the nearset cell of 0 from each cell
    // Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
    // Output: [[0,0,0],[0,1,0],[0,0,0]]
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dy = {-1, 0, 1, 0};
        vector<int> dx = {0, -1, 0, 1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if(new_x >=0 && new_y >=0 && new_x <n && new_y<m){
                    if(ans[new_x][new_y] > ans[x][y] + 1){
                        ans[new_x][new_y] = ans[x][y] + 1;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        return ans;
    }
};
