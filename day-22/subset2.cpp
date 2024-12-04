#include<iostream>
#include<vector>
using namespace std;

// time complexity o(2^N)
// space complexity o(N)
class Solution {
public:
    void helper(vector<int> nums, vector<int> op, int i, vector<vector<int>> &ans) {
        if(i == nums.size()){
            ans.push_back(op);
            return;
        }

        // picking up
        op.push_back(nums[i]);
        helper(nums, op, i+1, ans);
        op.pop_back();

        // not picking up
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        helper(nums, op, i+1, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        sort(nums.begin(), nums.end());
        helper(nums, op, 0, ans);
        return ans;
    }
};