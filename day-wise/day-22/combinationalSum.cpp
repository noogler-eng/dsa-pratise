// QUESTION - https://leetcode.com/problems/combination-sum/submissions/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void helper(vector<int> candidates, int target, int i, vector<int> op, int sum, vector<vector<int>>& ans){
        if(sum == target){
            ans.push_back(op);
            return;
        }

        if(sum > target) return;

        // selecting
        // repetion of the smae number is allwoed
        op.push_back(candidates[i]);
        helper(candidates, target, i, op, sum + candidates[i], ans);
        op.pop_back();

        // not selecting
        if(i+1 < candidates.size()){
            helper(candidates, target, i+1, op, sum, ans);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        helper(candidates, target, 0, op, 0, ans);
        return ans;
    }
};