// QUESTION - https://leetcode.com/problems/word-ladder/description/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// thiis is hard but nice problem
class Solution {
public:
    // there is a brute force approach exists
    // simply appying the bfs and using level
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, bool> m;
        for(int i=0; i<wordList.size(); i++){
            m[wordList[i]] = true;
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        m.erase(beginWord);
        while(!q.empty()){
            string top = q.front().first;
            int level = q.front().second;
            string original = top;
            q.pop();

            for(int i=0; i<top.length(); i++){
                for(int j=0; j<26; j++){
                    top[i] = 'a' + j;
                    if(m.find(top) != m.end()){
                        m.erase(top);
                        q.push({top, level+1});
                        if(top == endWord) return level+1;
                    }
                }
                top = original;
            }
        }
        return 0;
    }
};