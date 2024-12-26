// Longest Common Prefix
// QUESTION - https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string commonOne = s[0];
        for(int j=0; j<commonOne.length(); j++){
            for(int i=1; i<s.size(); i++){
                if(commonOne[j] != s[i][j]) return commonOne.substr(0, j);
            }
        }

        return commonOne;
    }
};