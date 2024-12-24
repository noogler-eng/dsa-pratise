// QUESTION - https://leetcode.com/problems/rotting-oranges/description/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int freshOranges = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }

                if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        int maxTime = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            q.pop();

            maxTime = max(maxTime, time);
            for(int i=0; i<4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && grid[new_x][new_y] == 1){
                    freshOranges--;
                    q.push({{new_x, new_y}, time+1});
                    grid[new_x][new_y] = 2;
                }
            }
        }
        return freshOranges == 0 ? maxTime: -1;
    }
};