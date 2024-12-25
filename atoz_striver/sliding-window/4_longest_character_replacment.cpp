// longest repeating character replacement
// QUESTION - https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include<iostream>
#include<vector>
using namespace std;

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// first we are taking the element
// finding the max fre element
// if max len - max element > k then reduce it
// taking length of each time

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0;
        int max_length = 0;
        unordered_map<char, int> m;
        int maxi = INT_MIN;
        while(j < s.length()){
            m[s[j]]++;
            maxi = max(maxi, m[s[j]]);
            while((j-i+1) - maxi > k){
                m[s[i]]--;
                i++;
            }
            max_length = max(max_length, j-i+1);
            j++;
        }
        return max_length;
    }
};