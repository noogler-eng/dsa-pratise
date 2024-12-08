#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void helper(int k, int n, int i, vector<int> &op, vector<vector<int>> &ans){
        if(k == 0 && n == 0){
            ans.push_back(op);
            return;
        }

        if(i > 9 || k < 0 || n < 0){
            return;
        }

        // picking up
        op.push_back(i);
        helper(k-1, n-i, i+1, op, ans);
        op.pop_back();

        // not picking up
        helper(k, n, i+1, op, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> op;
        helper(k, n, 1, op, ans);
        return ans;
    }
};