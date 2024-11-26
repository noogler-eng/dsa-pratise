// QUESTION - https://www.geeksforgeeks.org/problems/rod-cutting0840/1

#include<iostream>
#include<vector>
using namespace std;

// different question and important
// int costs = 1, 5, 8, 9, 10, 17, 17, 20
// collecting the rod lengths in maxmise the selling cost
// time complexity o(N*N)
// space complexity o(2N)
int cutting_rod_cost(vector<int> costs){
    int n = costs.size();
    vector<vector<int>> table(costs.size()+1, vector<int>(costs.size()+1));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(i <= j){
                // either take or untake
                table[i][j] = max(table[i][j-i] + costs[i-1], table[i-1][j]);
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }
    return table[n][n];
}

int main(){
    vector<int> sell_price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<cutting_rod_cost(sell_price)<<endl;
    return 0;
}