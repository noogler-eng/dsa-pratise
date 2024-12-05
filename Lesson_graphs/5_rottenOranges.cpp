// QUESTION - https://leetcode.com/problems/rotting-oranges/
// implement using BFS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// time complexity o(n*m) + o(n*m)*4
// space complexity o(n*m)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int countOranges = 0;
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
                if(grid[i][j]!=0) countOranges++;
            }
        }
     
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        int count = 0;
        int ans = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int level = q.front().second;
            count++;
            ans = max(ans, level);
            q.pop();
            for(int i=0; i<dx.size(); i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size() && grid[new_x][new_y] == 1){
                    q.push({{new_x, new_y}, level+1});
                    grid[new_x][new_y] = 2;
                }
            }
        }


        if(count == countOranges) return ans;
        return -1;
    }
};