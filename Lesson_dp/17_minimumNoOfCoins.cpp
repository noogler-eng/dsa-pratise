// QUESTION - https://leetcode.com/problems/coin-change/description/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space complexity o(2N)
int minimum_no_of_coins_required(vector<int> coins, int target){
    vector<vector<int>> table(coins.size() + 1, vector<int>(target + 1, INT_MAX));
    for (int i = 0; i < coins.size() + 1; i++)
        table[i][0] = 0;

    for (int i = 1; i < coins.size() + 1; i++) {
        for (int j = 1; j < target + 1; j++) {
            if (coins[i - 1] <= j) {
                // selecting or not
                int mini;
                if(table[i][j - coins[i - 1]] == INT_MAX) {
                    mini = table[i - 1][j];
                }else{
                    mini = min(table[i][j - coins[i - 1]] + 1, table[i - 1][j]);
                }
                table[i][j] = mini;
            } else {
                // not selecting
                table[i][j] = table[i - 1][j];
            }
        }
    }

    if(table[coins.size()][target] == INT_MAX) return -1;
    return table[coins.size()][target];
}

int main(){
    vector<int> coins = {1, 2, 5};
    int target = 11;
    cout<<minimum_no_of_coins_required(coins, target)<<endl;
    return 0;
}