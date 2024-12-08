// QUESTION - https://leetcode.com/problems/generate-parentheses/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

// time complexity o(2^N)
// space complexity o(1)
class Solution {
public:
    void helper(int open, int closed, string input, vector<string> &ans){
        if(open == 0 && closed == 0) {
            ans.push_back(input);
            return;
        }

        if(open > closed){
            return;
        }else{
            if(open > 0){
                string inp1 = input + '(';
                string inp2 = input + ')';
                helper(open-1, closed, inp1, ans);
                helper(open, closed-1, inp2, ans);
            }else{
                string inp2 = input + ')';
                helper(open, closed-1, inp2, ans);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        // everytime the length must be even
        helper(n, n, "", ans);
        return ans;
    }
};