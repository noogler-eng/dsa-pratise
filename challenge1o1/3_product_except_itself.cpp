// QUESTION - https://leetcode.com/problems/product-of-array-except-self/
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// conditions: 
// You must write an algorithm that runs in O(n) time and without using the division operation.
// time complexity o(3N)
// space complexity o(2N)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> from_right(n);
        vector<int> from_left(n);
        vector<int> ans(n);

        int fl = 1;
        for(int i=0; i<n; i++){
            from_left[i] = fl;
            fl = fl * nums[i];
        }

        int fr = 1;
        for(int i=n-1; i>=0; i--){
            from_right[i] = fr;
            fr = fr * nums[i];
        }

        for(int i=0; i<n; i++){
            ans[i] = from_right[i] * from_left[i];
        }

        return ans;
    }
};