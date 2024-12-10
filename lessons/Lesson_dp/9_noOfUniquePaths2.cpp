// QUESTION - https://leetcode.com/problems/unique-paths-ii/

#include<iostream>
#include<vector>
using namespace std;

// we can either move right or down
// 1 means there is blockage
// time complexity o(N*N)
// space complexity o(N*N)
int no_of_unique_paths(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    if (grid[0][0] == 1) return 0;

    vector<vector<int>> table(n, vector<int>(m, 0));

    // this is because we can only move in 1st colmun downward so if in between
    // anyone becomes 1 then no way for next one to get travesed as we move only down and right
    int marked = 1;
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) {
            table[i][0] = 0;
            marked = 0;
        }
        else table[i][0] = marked;
    }

    // this is because we can only move in 1st colmun downward so if in between
    // anyone becomes 1 then no way for next one to get travesed as we move only down and right
    marked = 1;
    for (int i = 0; i < m; i++) {
        if (grid[0][i] == 1) {
            table[0][i] = 0;
            marked = 0;
        }
        else table[0][i] = marked;
    };

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == 1) table[i][j] = 0;
            else table[i][j] = table[i - 1][j] + table[i][j - 1];
        }
    }

    return table[n - 1][m - 1];
}

int main(){
    vector<vector<int>> maze = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    cout<<no_of_unique_paths(maze)<<endl;
    return 0;
}