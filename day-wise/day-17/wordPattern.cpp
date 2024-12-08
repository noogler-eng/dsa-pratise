// QUESTION LINK: https://leetcode.com/problems/word-pattern/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void print(vector<string> p){
    for(auto i: p) cout<<i<<" ";
    cout<<endl;
}

// time complexity o(2N)
// space complexity o(3N)
bool wordPattern(string pattern, string s){
    vector<string> store;
    unordered_map<char, string> m;
    unordered_map<string, char> v;

    int i = 0;
    string new_word = "";
    s += ' ';
    while (i < s.length()) {
        if (s[i] == ' ') {
            store.push_back(new_word);
            new_word = "";
        } else {
            new_word += s[i];
        }
        i++;
    }

    if (pattern.length() != store.size())
        return false;

    for (int j = 0; j < pattern.length(); j++) {
        if (m.find(pattern[j]) == m.end()) {
            m[pattern[j]] = store[j];
            if(v.find(store[j]) != v.end()) return false;
            else v[store[j]] = pattern[j];
        } else {
            if (m[pattern[j]] != store[j])
                return false;
        }
    }

    return true;
}

int main(){
    cout<<wordPattern("abba", "dog cat cat fish")<<endl;
    return 0;
}