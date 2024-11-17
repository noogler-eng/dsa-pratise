// Question Link - https://leetcode.com/problems/univalued-binary-tree/

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;
        Node(int data){
            this->data = data;
            this->right = NULL;
            this->left = NULL;
        }
};

bool traversing_tree(Node* root, int target){
    // traversal of tree by DFS, post_orderTraversal
    if(root == NULL) return true;
    return (root->data == target && traversing_tree(root->left, target) && traversing_tree(root->right, target));
}   

// optmized way
// time complexity is o(N), traversing all the nodes
// space complexity o(1)
bool is_univalued_binary_tree(Node* root){
    return traversing_tree(root, root->data);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(1);
    root->right = new Node(1);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    root->right->right = new Node(1);
    cout<<is_univalued_binary_tree(root)<<endl;
    return 0;
}