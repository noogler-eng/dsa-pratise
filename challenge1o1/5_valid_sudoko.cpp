// QUESTION - https://leetcode.com/problems/valid-sudoku/

#include<iostream>
#include<vector>
using namespace std;

// steps -
// 1. checking each row
// 2. checking each coloums
// 3. checking ech block
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // validating the rows
        for(int i=0; i<9; i++){
            vector<int> isVis(10, false);
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(isVis[board[i][j] - '0'] == true) return false;
                    isVis[board[i][j] - '0'] = true;
                }
            }
        }

        // validating the coloumns
        for(int i=0; i<9; i++){
            vector<int> isVis(10, false);
            for(int j=0; j<9; j++){
                if(board[j][i] != '.'){
                    if(isVis[board[j][i] - '0'] == true) return false;
                    isVis[board[j][i] - '0'] = true;
                }
            }
        }

        // validating blocks
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                vector<int> isVis(10, false);
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        int row = k + (3 * i);
                        int col = l + (3 * j);
                        if(board[row][col] != '.'){
                            if(isVis[board[row][col] - '0'] == true) return false;
                            isVis[board[row][col] - '0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};