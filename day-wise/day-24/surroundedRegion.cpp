// QUESTION - https://leetcode.com/problems/surrounded-regions/description/

#include<iostream>
#include<vector>
using namespace std;

// input: [
//  ["X","X","X","X"],
//  ["X","O","O","X"],
//  ["X","X","O","X"],
//  ["X","O","X","X"]]

// output: [
//  ["X","X","X","X"],
//  ["X","X","X","X"],
//  ["X","X","X","X"],
//  ["X","O","X","X"]] 

// mark 1 to edge cases 
void dfs(vector<vector<char>>& board, int i, int j, int n, int m){
    board[i][j] = 1;
    int x = i;
    int y = j;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m &&
            board[new_x][new_y] == 'O') {
            dfs(board, new_x, new_y, n, m);
        }
    }
}

void solve(vector<vector<char>>& board){
    // we have to submerge the sourrounded region
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                board[i][j] == 'O') {
                dfs(board, i, j, n, m);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == 1) board[i][j] = 'O';
        }
    }
}