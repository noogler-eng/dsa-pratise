// QUESTION - https://leetcode.com/problems/minimum-path-sum/description/

#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> grid){
    for(auto i: grid){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

// time complexity o(N*N)
// space compleity o(N*N)
int min_path_sum(vector<vector<int>> grid){
    if(grid.size() == 1) return grid[0][0];
    
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> table(n+1, vector<int>(m+1, INT_MAX));
    table[0][1] = 0;
    table[1][0] = 0;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            int from_top = table[i-1][j];
            int from_left = table[i][j-1];
            table[i][j] = min(from_top, from_left) + grid[i-1][j-1];
            cout<<min(from_top, from_left)<<" "<<grid[i-1][j-1]<<endl;
        }
    }
    print(table);
    return table[n][m];
}

int main(){
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout<<min_path_sum(grid)<<endl;
    return 0;
}