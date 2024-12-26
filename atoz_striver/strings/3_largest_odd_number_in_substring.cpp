// largest odd number in string
// QUESTION - https://leetcode.com/problems/largest-odd-number-in-string/description/
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string s) {
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] % 2 == 1) {
                return s.substr(0, i+1);
            }
        }
        return "";
    }
};