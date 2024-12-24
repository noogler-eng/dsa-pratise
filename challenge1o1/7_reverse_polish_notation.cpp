// QUESTION - https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<iostream> 
#include<vector>
using namespace std;

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9

class Solution {
public:
    int evalute(int op1, int op2, string op) {
        if (op == "+") {
            return op1 + op2;
        } else if (op == "-") {
            return op2 - op1;
        } else if (op == "*") {
            return op1 * op2;
        } else {
            return op2 / op1;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int value = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                string op = tokens[i];
                // we have to push back the ans to stack again for further uses
                s.push(evalute(op1, op2, op));
            } else {
                string num = tokens[i];
                int sign = 1;
                int number = 0;
                for (int j = 0; j < num.length(); j++) {
                    if (num[j] == '-') {
                        sign = sign * -1;
                    } else if (num[j] == '+') {
                        sign = sign * 1;
                    } else {
                        number = (number * 10) + (num[j] - '0');
                    }
                }
                s.push(number * sign);
            }
        }
        return s.top();
    }
};