// QUESTION - https://leetcode.com/problems/implement-trie-prefix-tree/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
public:
    Node* arr[26];
    bool flag = false;
};

class Trie {
public:
    Node* root = NULL;
    Trie() { 
        this->root = new Node();
    }

    void insert(string word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            if (temp->arr[word[i] - 'a'] != NULL) {
                temp = temp->arr[word[i] - 'a'];
            } else {
                temp->arr[word[i] - 'a'] = new Node();
                temp = temp->arr[word[i] - 'a'];
            }
        }
        temp->flag = true;
    }

    bool search(string word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            if (temp->arr[word[i] - 'a'] == NULL) {
                return false;
            } else {
                temp = temp->arr[word[i] - 'a'];
            }
        }

        return temp->flag;
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (temp->arr[prefix[i] - 'a'] == NULL) {
                return false;
            } else {
                temp = temp->arr[prefix[i] - 'a'];
            }
        }
        return true;
    }
};