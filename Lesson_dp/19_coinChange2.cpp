// QUESTION - https://leetcode.com/problems/coin-change-ii/description/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space complexity o(2N)
// we can take a same coin infine number of times
int no_of_combinations(vector<int> coins, int amount){
    vector<vector<int>> table(coins.size() + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i < coins.size() + 1; i++) table[i][0] = 1;
    for (int i = 1; i < coins.size() + 1; i++) {
        for (int j = 1; j < amount + 1; j++) {
            int ans;
            if (coins[i - 1] <= j) {
                if(table[i][j - coins[i - 1]] > INT_MAX - table[i - 1][j]) ans = INT_MAX;
                else ans = table[i][j - coins[i - 1]] + table[i - 1][j];
                table[i][j] = ans;
            } else {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    return table[coins.size()][amount];
}

int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout<<no_of_combinations(coins, amount)<<endl;
    return 0;
}