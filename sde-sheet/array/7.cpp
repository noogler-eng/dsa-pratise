
#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space complexity o(1)
class Solution {
public:
    void reverse(vector<int> &mat){
        int start = 0;
        int end = mat.size()-1;
        while(start < end){
            swap(mat[start], mat[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i]);
        }
    }
};