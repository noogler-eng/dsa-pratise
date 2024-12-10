// Tries - 
// use in autocomplete suggestion in google, vscode
// ["word", "worb", "abcde", "abc"]
// hasing them to find wheather they exists or not
// m["word"]++ ...
// does any word exists which starts with "wo"
// "wo" -> "word", "worb"
// its hard to find using hashing (almost impossible)
// its gonna take a lot of space and more time complex

// total alphabet letters -> 26
// starting from a and end to z
// implementation of trie
// w -> o -> r -> b         "worb"
//             -> d         "word"
// a -> b -> c              "abc"
//             -> d -> e    "abcde"

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    // currently all are null, we want to store the next node in them
    // a + index gives the current letter
    Node* arr[26];
    // tell us wheather the word is complete or not at that point
    // flag true means word is complete.
    bool flag = false;
};

// entire dummy node
Node* root = new Node();

// inserting the word into the tries
void insert(string word){
    // starting from root and trvel in the direction of word
    // previously there might be a word
    Node* temp = root;
    for(int i=0; i<word.length(); i++){
        if(temp->arr[word[i]-'a'] == NULL){
            temp = temp->arr[word[i]-'a'];
        }else{
            temp->arr[word[i]-'a'] = new Node();
            temp = temp->arr[word[i]-'a'];
        }
    }
    // at the end it will make the word is complete
    temp->flag = true;
}

// finding if the word exists or not in tries
bool search(string word){
    // starting from the root;
    Node* temp = root;
    for(int i=0; i<word.length(); i++){
        if(temp->arr[word[i]-'a'] == NULL){
            return false;
        }else{
            temp = temp->arr[word[i]-'a'];
        }
    }
    // checking for is the search word is there or not, in not condition there will be another word with same prefix
    return temp->flag;
}

bool startsWith(string prefix){
    Node* temp = root;
    for(int i=0; i<prefix.length(); i++){
        if(temp->arr[prefix[i]-'a'] == NULL){
            return false;
        }else{
            temp = temp->arr[prefix[i]-'a'];
        }
    }
    // checking for is the search word is there or not, in not condition there will be another word with same prefix
    return true;
}



