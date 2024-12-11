// QUESTION - https://leetcode.com/problems/valid-anagram/submissions/1476103592/

#include<iostream>
#include<unordered_map>
#include<map>
#include<string>

// time complexity o(2N)
// space complexity o(N)
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        for(int i=0; i<s.length(); i++){
            m[s[i]]++;
        }

        for(int i=0; i<t.length(); i++){
            if(m.find(t[i])!=m.end()){
                m[t[i]]--;
                if(m[t[i]] == 0){
                    m.erase(t[i]);
                }
            }else {
                return false;
            }
            
        }
        if(m.size() == 0) return true;
        return false;
    }
};