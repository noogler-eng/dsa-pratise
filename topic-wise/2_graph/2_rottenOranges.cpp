// QUESTION - https://leetcode.com/problems/rotting-oranges/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// time complexity - o(N*N) + 4 * o(N*N)
// space complexity - o(N) + o(4)*2
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int fresh_oranges = 0;
        int max_level = 0;
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
                if(grid[i][j] == 1){
                    fresh_oranges++;
                }
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int level = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int new_x = dx[i] + x;
                int new_y = dy[i] + y;
                if(new_x >= 0 && new_y >= 0 && new_x <n && new_y < m && grid[new_x][new_y] == 1){
                    grid[new_x][new_y] = 2;
                    max_level = max(max_level, level+1);
                    q.push({{new_x, new_y}, level+1});
                    fresh_oranges--;
                }
            }
        }

        if(fresh_oranges != 0) return -1;
        return max_level;
    }
};