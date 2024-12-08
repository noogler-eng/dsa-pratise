// QUESTION - https://leetcode.com/problems/subsets/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // time complexity o(2^N)
    // space complexity o(N)
    void all_subsets(vector<int> nums, vector<int> op, int i, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(op);
            return;
        }

        // selecting
        op.push_back(nums[i]);
        all_subsets(nums, op, i+1, ans);
        op.pop_back();
        // non selecting
        all_subsets(nums, op, i+1, ans);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        all_subsets(nums, op, 0, ans);
        return ans;
    }
};