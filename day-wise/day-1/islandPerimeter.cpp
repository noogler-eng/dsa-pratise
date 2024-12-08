// Question link - https://leetcode.com/problems/island-perimeter/

#include<iostream>
#include<vector>
using namespace std;

// wrost case, optmial case
// time complexity o(N*N)
// space complexity o(1)
int island_perimeter(vector<vector<int>> mat){

    int parameter = 0;
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size(); j++){
            if(mat[i][j] == 1){
                // seeing the left side 
                if(j == 0 || (j > 0 && mat[i][j-1] == 0)) parameter++;
                // seeing the right side
                if(j == mat[0].size() - 1 || (j < mat[0].size() - 1 && mat[i][j+1] == 0 )) parameter++;
                // seeing the bottom side
                if(i == mat.size() - 1 || (i < mat.size() - 1 && mat[i+1][j] == 0)) parameter++;
                // seeing the top side
                if(i == 0 || (i > 0 && mat[i-1][j] == 0)) parameter++;
            }
        }
    }

    return parameter;
}

int main(){
    vector<vector<int>> mat = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout<<island_perimeter(mat)<<endl;
    return 0;
}