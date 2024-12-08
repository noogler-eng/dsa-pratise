// QUESTION LINK: https://leetcode.com/problems/insert-into-a-binary-search-tree/

#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// time complexity o(H)
// space complexity o(1)
Node* insert_into_binary_search(Node* temp, int key){
    if(temp == NULL) {
        Node* node = new Node(key);
        return node;
    } 

    Node* root = temp;
    while(root!=NULL){
        if(key > root->data) {
            if(root->right == NULL){
                root->right = new Node(key);
                return temp;
            }
        }else{
            if(root->left == NULL){
                root->left = new Node(key);
                return temp;   
            }
        }
        if(key > root->data) root = root->right;
        else root = root->left;
    }

    root = new Node(key);
    return temp;
} 


void print(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}   


int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    int val = 5;

    // in binary search tree it is sure that left is maller then root and right is greater then root
    print(root);
    cout<<endl;
    Node* ans = insert_into_binary_search(root, val);
    print(ans);
    return 0;
}