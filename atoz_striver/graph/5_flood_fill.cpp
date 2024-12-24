// QUESTION - https://leetcode.com/problems/flood-fill/description/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// time complexity o(N*N) + o(v + 2E)
// space complexity o(N) + o(8)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        int sartingColor = image[sr][sc];
        if(sartingColor == color) return image;
        int n = image.size();
        int m = image[0].size();

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        q.push({sr, sc});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            image[x][y] = color;
            for(int i=0; i<4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && image[new_x][new_y] == sartingColor){
                    q.push({new_x, new_y});
                }
            }
        }
        return image;
    }
};