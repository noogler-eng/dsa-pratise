// QUESTION - https://leetcode.com/problems/number-of-enclaves/description/

#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int x, int y, int n, int m){
    grid[x][y] = -1;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    for(int i=0; i<4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < m &&
            grid[new_x][new_y] == 1){
                dfs(grid, new_x, new_y, n, m);
            }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 1){
                dfs(grid, i, j, n, m);
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
                cnt++;
            }
        }
    }
    return cnt;
}