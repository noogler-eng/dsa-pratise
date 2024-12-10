#include<iostream>
using namespace std;
class Node{
    public:
        Node* arr[26];
        int noOfSetFlag = 0;
        int cntPrfix = 0;
};

class Trie{
    // initlized all with 0
    public: 
        Node* root = NULL;
        Trie(){
            this->root = new Node();
        }

        void insert(string word){
            Node* temp = root;
            for(int i=0; i<word.length(); i++){
                int index = word[i] - 'a';
                if(temp->arr[index] == NULL) temp->arr[index] = new Node();
                temp = temp->arr[index];
                temp->cntPrfix++;
            }
            temp->noOfSetFlag++;

        }

        // countinf the no of equal string 
        int no_of_string_equals_to_word(string word){
            Node* temp = root;
             for(int i=0; i<word.length(); i++){
                int index = word[i] - 'a';
                if(temp->arr[index] == NULL) return 0;
                temp = temp->arr[index];
            }
            return temp->noOfSetFlag;
        }

        // giving all the string with this prefix of length
        int no_of_string_having_prefix_equal_to_prefix(string prefix){
            Node* temp = root;
            for(int i=0; i<prefix.length(); i++){
                int index = prefix[i] - 'a';
                if(temp->arr[index] == NULL) return 0;
                temp = temp->arr[index];
            }
            return temp->cntPrfix;
        }

        // deleting the single word with word
        // remeber to decrease the cntPrefixes
        void erase(string word){
            Node* temp = root;
            for(int i=0; i<word.length(); i++){
                int index = word[i] - 'a';
                if(temp->arr[index] == NULL) return;
                temp->cntPrfix--;
                temp = temp->arr[index];
            }
            if(temp->noOfSetFlag > 0) temp->noOfSetFlag--;
            return;
        }
};

