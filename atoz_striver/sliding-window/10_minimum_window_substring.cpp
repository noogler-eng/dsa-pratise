// Minimum Window Substring
// QuESTION - https://leetcode.com/problems/minimum-window-substring/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        // repeated character also must be included in s minimum substring
        for(int i=0; i<t.length(); i++){
            m[t[i]]++;
        }

        int i=0, j=0;
        int startIndex = 0;
        int count = 0;
        int actuall_size = m.size();
        int mini = INT_MAX;
        while(j < s.length()){
            m[s[j]]--;
            if(m[s[j]] == 0) count++;
            
            while(actuall_size == count){
                if(j-i+1 < mini){
                    startIndex = i;
                    mini = j-i+1;
                }
                m[s[i]]++;
                if(m[s[i]] > 0) count--;
                i++;
            }
            j++;
        }

        if(mini > s.length()) return "";
        return s.substr(startIndex, mini);
    }
};