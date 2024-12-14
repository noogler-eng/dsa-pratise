// QUESTION - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include<iostream>
using namespace std;

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, maxProfit = 0;
        for(int i=0; i<prices.size(); i++){
            int profit = prices[i] - mini;
            maxProfit = max(profit, maxProfit);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};