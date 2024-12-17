// QUESTION - https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        while(i < str1.length() && j < str2.length()){
            if(str1[i] == str2[j]){
                i++;
                j++;
            }else if(('a' + (str1[i] - 'a' + 1) % 26) == str2[j]){
                i++;
                j++;
            }else {
                i++;
            }
        }

        if(j == str2.length()) return true;
        return false;
    }
};