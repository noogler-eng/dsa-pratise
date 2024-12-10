// QUESTION - https://www.naukri.com/code360/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space complexity o(N)
int max_profit(vector<int> weights, vector<int> money, int W){

    vector<vector<int>> table(weights.size()+1, vector<int>(W+1, 0));
    for(int i=1; i<weights.size()+1; i++){
        for(int j=1; j<W+1; j++){
            if(weights[i-1] <= j){
                table[i][j] = max(table[i-1][j-weights[i-1]] + money[i-1], table[i-1][j]);
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }

    return table[weights.size()][W];
}

int main(){
    vector<int> weights = {1, 2, 4, 5};
    vector<int> money = {5, 4, 8, 6};
    int W = 5;
    cout<<max_profit(weights, money, W)<<endl;
    return 0;
}