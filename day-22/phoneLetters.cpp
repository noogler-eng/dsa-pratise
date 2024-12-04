#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void helper(string digits, vector<string> keys, int i,  string &input, vector<string> &ans){
        if(i == digits.size()){
            ans.push_back(input);
            return;
        }

        for(int j=0; j<keys[(digits[i]-'0')-1].length(); j++){
            string word = keys[(digits[i]-'0')-1];
            input.push_back(word[j]);
            helper(digits, keys, i+1, input, ans);
            input.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        vector<string> keys = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string input = "";
        helper(digits, keys, 0, input , ans);
        return ans;
    }
};