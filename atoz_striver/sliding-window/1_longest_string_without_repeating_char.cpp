// Longest Substring Without Repeating Characters
// QUESTION - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// 1. if element is found in the map then movie i forward by founding index
// 2. adding the new element in map with index
// 3. find the maxLength at each step 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int max_length = 0;
        int i=0, j=0;
        while(j < s.length()){
            if(m.find(s[j]) != m.end() && m[s[j]] >= i){
                i = m[s[j]]+1;
            }
            m[s[j]] = j;
            max_length = max(max_length, j-i+1);
            j++;
        }
        return max_length;
    }
};