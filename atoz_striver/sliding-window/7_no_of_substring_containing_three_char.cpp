// Number of substring containing all three characters
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int helper(string s, int k){
        int i=0, j=0;
        int count=0;
        unordered_map<char, int> m;
        while(j < s.length()){
            m[s[j]]++;
            while(m.size() > k){
                m[s[i]]--;
                if(m[s[i]] == 0) m.erase(s[i]);
                i++;
            }

            if(m.size() <= k){
                count+=(j-i+1);
            }
            j++;
        }
        return count;
    }

    int numberOfSubstrings(string s) {
        return helper(s, 3) - helper(s, 2);
    }
};