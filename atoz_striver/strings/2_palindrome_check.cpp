// Reverse words in a given string / Palindrome Check
// QUESTION - https://leetcode.com/problems/reverse-words-in-a-string/submissions/1488854589/
// nice question

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        s+=' ';
        string new_one = "";
        int j=0;
        
        // remove from front
        while(j < s.length()){
            if(s[j] != ' ') break;
            j++;
        }

        // remove from back
        while(j < s.length()){
            if(j != s.length()-1 && s[j] == ' ' && s[j+1] == ' ') {
                j++;
                continue;
            }
            if(s[j] == ' '){
                st.push(new_one);
                new_one = "";
            }else{
                new_one+=s[j];
            }
            j++;
        }

        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            if(st.size() > 1) ans+=' ';
            st.pop();
        }
        return ans;
    }
};