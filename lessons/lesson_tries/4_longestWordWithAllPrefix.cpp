// QUESTION - https://leetcode.com/problems/longest-word-with-all-prefixes/description/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Node{
    public:
        Node* arr[26];
        bool flag = false;
};

class Trie {
    public:
        Node* root = NULL;
        int maxSetFlags = 0;
        string ans = "";
        Trie(){
            this->root = new Node();
        }

        // one of the possible solution is sort all
        void insert(string word){
            Node* temp = root;
            int cntSetFlags = 0;
            for(int i=0; i<word.length(); i++){
                int index = word[i] - 'a';
                if(temp->arr[index] == NULL) temp->arr[index] = new Node();
                if(temp->flag == true) cntSetFlags++;
                temp = temp->arr[index];
            }
            temp->flag = true;
            if(cntSetFlags == word.length()-1){
                if(this->ans.length() < word.length()){
                    this->ans = word;
                }else if(this->ans.length() == word.length()){
                    ans = min(ans, word);
                }
            }
        }
};

string longest_Perfix(vector<string> words){
    Trie t;
    // sort all the strings;
    sort(words.begin(), words.end(), [](string &a, string &b){
        return a.length() < b.length();
    });

    for(int i=0; i<words.size(); i++){
        t.insert(words[i]);
    }

    return t.ans;
}

