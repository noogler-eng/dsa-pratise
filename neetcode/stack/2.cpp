// QUESTION - https://leetcode.com/problems/evaluate-reverse-polish-notation/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int getValue(int a, int b, string ops){
        if(ops == "+") return a + b;
        if(ops == "-") return b - a;
        if(ops == "*") return a * b;
        if(ops == "/") return b / a;
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "-" || tokens[i] == "/"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int value = getValue(a, b, tokens[i]);
                st.push(value);
            }else{
                int value = 0;
                int sign = 1;
                for(int j=0; j<tokens[i].length(); j++){
                    if(tokens[i][j] == '-') {
                        sign = -1;
                        continue;
                    }
                    value = value * 10 + (tokens[i][j] - '0');
                }
                st.push(value / sign);
            }
        }
        return st.top();
    }
};