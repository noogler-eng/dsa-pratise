// QUESTION - https://leetcode.com/problems/unique-paths/

#include<iostream>
using namespace std;

// using dp method
// time compelexity o(N*N)
// space complexity o(N*N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(m, vector<int>(n, 0));
        // no of ways traversing the bottom and right
        for (int i = 0; i < m; i++)
            table[i][0] = 1;
        for (int i = 0; i < n; i++)
            table[0][i] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // no of ways from up top
                int from_top = table[i - 1][j];
                // no of ways from left side
                int from_left = table[i][j - 1];
                table[i][j] = from_top + from_left;
            }
        }
        return table[m - 1][n - 1];
    }
};