// QUESTION - https://leetcode.com/problems/valid-palindrome/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool helper(string s){
        cout<<s<<endl;
        int start = 0;
        int end = s.length() - 1;
        while(start < end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    bool isPalindrome(string s) {
        if(s.length() <= 1) return true;
        string new_s = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] >= 'A' && s[i] <='Z'){
                new_s.push_back(s[i]-'A'+'a');
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                new_s.push_back(s[i]);
            }else if(s[i] >= '0' && s[i] <= '9'){
                new_s.push_back(s[i]);
            }
        }

        return helper(new_s);
    }
};