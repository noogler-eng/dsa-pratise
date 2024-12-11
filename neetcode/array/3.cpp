// QUESTION - https://leetcode.com/problems/group-anagrams/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// time complexity O(Nlog(l/2)) + o(N)
// space complexity o(N) for map
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(int i=0; i<n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }  

        for(auto i: m){
            ans.push_back(i.second);
        }
        return ans;
    }
};