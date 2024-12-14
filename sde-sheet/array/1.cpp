// QUESTION - https://leetcode.com/problems/set-matrix-zeroes/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*M) + (N*M)
// space complexity o(1)
class Solution {
public:
    void markRow0(vector<vector<int>>& matrix, int row){
        int n = matrix[0].size();
        for(int i=0; i<n; i++){
            matrix[row][i] = 0;
        }
    }

    void markCol0(vector<vector<int>>& matrix, int col){
        int n = matrix.size();
        for(int i=0; i<n; i++){
            matrix[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int extra_col = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0){
                        matrix[0][j] = 0;
                    }else{
                        extra_col = 0;
                    }
                }
            }
        }
        
        // first checking the coloumms
        for(int i=1; i<m; i++){
            if(matrix[0][i] == 0) markCol0(matrix, i);
        }

        // cheking the row 
        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0) markRow0(matrix, i);
        }

        // lastly checking thr first col line
        if(extra_col == 0) markCol0(matrix, 0);
    }
};