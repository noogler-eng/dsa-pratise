// QUESTION - https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/description/
// number of distinct substring in string
// generic way of doing this is double loop and set, here time complexity are o(n*n) and space is o(n*n*n)
// n*n is no of string and n/2 is string sie (average)
// if space complexity is o(n*n*n) then always there is memeory limit exceeded


// time complexity o(N*N)
// space compelxity o(26) * o(N)
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
    public:
        Node* arr[26];
        bool flag = false;
};

class Trie {
    public:
        int noOfDiffSubstrings = 0;
        Node* root = NULL;
        Trie(){ 
            this->root = new Node();
        }

        void insert(int start, string word){
            Node* temp = root;
            for(int i=start; i<word.length(); i++){
                int index = word[i] - 'a';
                if(temp->arr[index] == NULL) {
                    temp->arr[index] = new Node();
                    this->noOfDiffSubstrings++;
                    temp->flag = true;
                }
                temp = temp->arr[index];
            }   
        }
};

int get_all_unique_strings(string word){
    Trie t;
    for(int i=0; i<word.length(); i++){
        t.insert(i, word);
    }
    return t.noOfDiffSubstrings;
}