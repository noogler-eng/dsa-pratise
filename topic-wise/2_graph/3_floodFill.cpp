// QUESTION - https://leetcode.com/problems/flood-fill/description/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// time complexity o(N)
// space complexity o(1) + 2 * o(4)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int temp_color = image[sr][sc];
        if(temp_color == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            image[x][y] = color;

            for(int i=0; i<4; i++){
                int new_x = dx[i] + x;
                int new_y = dy[i] + y;
                if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && image[new_x][new_y] == temp_color){
                    q.push({new_x, new_y});
                }
            }
        }
        return image;
    }
};