// QUESTION - https://leetcode.com/problems/product-of-array-except-self/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N) * 3
// space complexity o(2N) not include ans vector
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n,1);
        vector<int> ans(n);

        // moving forward
        int product = 1;
        for(int i=0; i<nums.size(); i++){
            prefix[i] = product;
            product = product * nums[i];
        }

        // moving downward
        product = 1;
        for(int i=nums.size()-1; i>=0; i--){
            suffix[i] = product;
            product = product * nums[i];
        }

        for(int i=0; i<nums.size(); i++){
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};