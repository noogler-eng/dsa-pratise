// QUESTION - https://leetcode.com/problems/surrounded-regions/

#include<iostream>
#include<vector>
using namespace std;

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// time complexity o(N*N)
// space complexity o(1)
class Solution {
public:
    void helper(vector<vector<char>>& board, int x, int y){
        board[x][y] = '1';
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        for(int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x >= 0 && new_y >= 0 && new_x < board.size() && new_y < board[0].size() && board[new_x][new_y] == 'O'){
                helper(board, new_x, new_y);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || i == n-1){
                    if(board[i][j] == 'O'){
                        helper(board, i, j);
                    }
                } 
                if(j == 0 || j == m-1){
                    if(board[i][j] == 'O'){
                        helper(board, i, j);
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};