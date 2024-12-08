// QUESTION LINK: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* right;
        Node* left;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// traversing inorder
void sum_of_root_to_leaf_binary(Node* root, int &total_sum, int num){
    if(root == NULL){
        return;
    }

    num = num << 1 | root->data;
    // if both are null then it is leaf node 
    if(root->right == NULL && root->left == NULL){
        total_sum += num;
        return;
    }
    sum_of_root_to_leaf_binary(root->left, total_sum, num);
    sum_of_root_to_leaf_binary(root->right, total_sum, num);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(0);
    root->right = new Node(1);
    root->left->left = new Node(0);
    root->left->right = new Node(1);
    root->right->left = new Node(0);
    root->right->right = new Node(1);
    int ts = 0;
    sum_of_root_to_leaf_binary(root, ts, 0);
    cout<<ts<<endl;
    return 0;
}