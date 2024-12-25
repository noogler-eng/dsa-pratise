// QUESTION - https://leetcode.com/problems/count-paths-with-the-given-xor-value/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int maxXor = 1024; // Maximum possible XOR value (based on constraints)
        vector<vector<vector<int>>> table(n, vector<vector<int>>(m, vector<int>(maxXor, 0)));
        table[0][0][grid[0][0]] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int x = 0; x < maxXor; ++x) {
                    if (table[i][j][x] > 0) {
                        // Moving down
                        if (i + 1 < n) {
                            table[i + 1][j][x ^ grid[i + 1][j]] += table[i][j][x];
                        }
                        // Moving right
                        if (j + 1 < m) {
                            table[i][j + 1][x ^ grid[i][j + 1]] += table[i][j][x];
                        }
                    }
                }
            }
        }

        return table[n-1][m-1][k];
    }   
};