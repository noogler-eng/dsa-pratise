// Remove outermost Paranthesis
// QUESTION - https://leetcode.com/problems/remove-outermost-parentheses/description/

#include<iostream>
#include<vector>
using namespace std;

// Input: s = "(()())(())"
// Output: "()()()"
// Explanation: 
// The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
// After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

// the concept of the increasing the depth and decreasing the depth
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    ans += c;
                }
                depth++;
            } else {
                depth--; 
                if (depth > 0) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};
