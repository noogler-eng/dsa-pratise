// QUESTION - https://leetcode.com/problems/encode-and-decode-strings/description/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string codedString = "";
        for(int i=0; i<strs.size(); i++){
            int size = strs[i].length();
            codedString.push_back(size+'0');
            codedString+='#';
            codedString+=strs[i];
        }
        return codedString;
    }

    vector<string> decode(string s) {
        cout<<s<<endl;
        int i=0;
        vector<string> ans;
        while(i < s.length()){
            int size = 0;
            while(s[i] != '#'){
                size = size * 10 + (s[i]-'0');
                i++;
            }
            i++;
            // always remember the substring, it will help us
            // string.substr(from, until that);
            string anss = s.substr(i, size);
            ans.push_back(anss);
            i = i + size;
        }
        return ans;
    }
};

