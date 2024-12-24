// QUESTION - https://leetcode.com/problems/generate-parentheses/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(2^N)
// space complexity o(1)
class Solution {
public:
    void helper(vector<string> &ans, int open, int close, string op){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }

        if(open < close){
            helper(ans, open, close-1, op + ')');
        }
        
        if(open > 0){
            helper(ans, open-1, close, op + '(');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, n, n, "");
        return ans;
    }
};