// QUESTION - https://leetcode.com/problems/triangle/description/

#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> table){
    for(auto i: table){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int min_path_sum_of_triangle(vector<vector<int>> triangle){
    if(triangle.size() == 1) return triangle[0][0];

    int n = triangle.size();
    int m = triangle[n-1].size();
    vector<vector<int>> table(n, vector<int>(m));
    
    int ans = INT_MAX;
    table[0][0] = triangle[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<i+1; j++){
            int mini;
            if(j-1 < 0) mini = table[i-1][j];
            else if(j >= i) mini = table[i-1][j-1];
            else mini = min(table[i-1][j], table[i-1][j-1]);
            table[i][j] = mini + triangle[i][j];
            if(i == n-1) ans = min(ans, table[i][j]);
        }
    }

    return ans;
}   

int main(){
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout<<min_path_sum_of_triangle(triangle)<<endl;
    return 0;
}