// Lowest Common Ancestor In Binary Tree

#include<iostream>
using namespace std;

// we have to find the lowest common ancestor of two nodes
// the ancestor that exists at the deepest level

// step.1 find the path from the root of both nodes   
// step.2 fing the last common point is LCA

class Node {
    public:
    int data;
    Node* right = NULL;
    Node* left = NULL;
    Node(int data){
        this->data = data;
    }
};

// time complexity o(N)
// space complexity O(1)
Node* helper(Node* root, Node* firstNode, Node* secondNode){
    if(root == NULL || root == firstNode || root == secondNode) return root;
    
    
    Node* left = helper(root->left, firstNode, secondNode);
    Node* right = helper(root->right, firstNode, secondNode);
    
    if(left == NULL) return right;
    else if(right == NULL) return left;
    // neither left null nor right null then
    return root;
}

Node* findingLowesAncestor(Node* root, Node* firstNode, Node* secondNode){
    Node* lca = helper(root, firstNode, secondNode);
    return lca;
}