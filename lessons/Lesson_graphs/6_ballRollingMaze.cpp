// LEETCODE - PREMIUM
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// start vector contians x and y
// destination vector contains x and y
bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination){
    int n = maze.size();
    int m = maze[0].size();

    queue<pair<int, int>> q;
    q.push({start[0], start[1]});

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        maze[x][y] = 1;
        q.pop();

        if(x == destination[0] && y == destination[1]) return true;

        for(int i=0; i<4; i++){
            int new_x = x;
            int new_y = y;
            
            // insider constrint 
            while(x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0){
                new_x = new_x + dx[i];
                new_y = new_y + dy[i];
            }

            // after this either crossed bound or stopeed at one
            new_x = new_x - dx[i];
            new_y = new_y - dy[i];
            if(maze[new_x][new_y] == 0){
                maze[new_x][new_y] = 1;
                q.push({new_x, new_y});
            }
        }
    }

    return false;
}