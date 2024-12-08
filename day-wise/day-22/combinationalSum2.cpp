#include<iostream>
#include<vector>
using namespace std;

// time complexity o(2^N)
// space complexity o(N)
// we dont count here return vector
class Solution {
public:
    void helper(vector<int> candidates, int target, int i, vector<int> &op, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(op);
            return;
        }

        if(i >= candidates.size() || target < 0) return;

        // picking up
        op.push_back(candidates[i]);
        helper(candidates, target - candidates[i], i+1, op, ans);
        op.pop_back();
        
        // no tpicking up
        while(i+1 < candidates.size() && candidates[i+1] == candidates[i]) i++;
        helper(candidates, target, i+1, op, ans);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;

        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, op, ans);
        return ans;
    }
};