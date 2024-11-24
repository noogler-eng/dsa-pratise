// QUESTION - https://leetcode.com/problems/rearrange-k-substrings-to-form-target-string/

#include <iostream>
#include<unordered_map>
using namespace std;

// time complexity o(2N)
// space complexity o(N)
bool isPossibleToRearrange(string s, string t, int k) {
    unordered_map<string, int> m;
    int size = t.length() / k, z = 0;
    string word = "";
    // entering
    for(int i=0; i<t.length(); i++){
        word+=t[i];
        z++;
        if(z == size) {
            cout<<word<<" ";
            m[word]++;
            z = 0;
            word = "";
        }
    }

    // deleting
    word = "";
    for(int i=0; i<s.length(); i++){
        word+=s[i];
        z++;
        if(z == size) {
            if(m.find(word) == m.end()) return false;
            else {
                m[word]--;
                if(m[word] == 0) m.erase(word);
            }
            z = 0;
            word = "";
        }
    }

    if(m.size() == 0) return true;
    else return false;
}

int main() {
    cout<<isPossibleToRearrange("aabbcc", "bbaacc", 3)<<endl;
    return 0;
}