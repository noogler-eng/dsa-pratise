// QUESTION - https://leetcode.com/problems/minimum-falling-path-sum/description/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space complexity o(N*N)
int minimum_falling_path_sum(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    if (n == 1 && m == 1)
        return grid[0][0];

    vector<vector<int>> table(n + 1, vector<int>(m + 1));
    for (int i = 0; i < m + 1; i++)
        table[0][i] = 0;
    for (int i = 0; i < n + 1; i++)
        table[i][0] = INT_MAX;
    table[0][0] = 0;

    int ans = INT_MAX;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            int mini;
            if(j == m) mini = min(table[i - 1][j], table[i - 1][j - 1]);
            else mini = min(min(table[i - 1][j], table[i - 1][j - 1]), table[i - 1][j + 1]);
            table[i][j] = mini + grid[i - 1][j - 1];
            if (i == n) ans = min(ans, table[i][j]);
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> grid = {{-19, 57}, {-40, -5}};
    cout<<minimum_falling_path_sum(grid)<<endl;
    return 0;
}