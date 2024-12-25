// QUESTION - https://leetcode.com/problems/number-of-enclaves/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& grid, int x, int y){
        grid[x][y] = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        for(int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x >= 0 && new_y >= 0 && new_x < grid.size() && new_y < grid[0].size() && grid[new_x][new_y] == 1){
                helper(grid, new_x, new_y);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == 1){
                        helper(grid, i, j);
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};