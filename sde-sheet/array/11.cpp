// QUESTION - https://leetcode.com/problems/search-a-2d-matrix/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // time complexity o(m+n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // here there is no sqare matrx so remember
        int row = 0, col = matrix[0].size()-1;
        while(row < matrix.size() && col > -1){
            if(matrix[row][col] == target) return true;
            else if (target > matrix[row][col]) row++;
            else col--;
        }
        return false;
    }
};