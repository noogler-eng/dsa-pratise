// QUESTION - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=problem-list-v2&envId=greedy

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // prices [7, 1, 5, 3, 6, 4]
    // points [_, _, 4, _, 3, _]
    // profit = 7
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i] > prices[i-1]){
                profit+=(prices[i] - prices[i-1]);
            }
        }

        return profit;
    }
};