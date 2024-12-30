// Root To Node Path
#include<iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node(int x){
        this->data = x;
    }
};

// inordered traversal
// Root, Left, Right
bool inorder_traversal(Node* root, Node* node, vector<int> &ans){
    if(root == NULL) return;

    ans.push_back(root->data);
    if(root == node) return true;
    if( inorder_traversal(root->left, node, ans) || inorder_traversal(root->right, node, ans)){
        return true;
    }

    ans.pop_back();
    return false;
}

vector<int> print_shortest_path_between_root_and_node(Node* root, Node* node){
    vector<int> ans;
    cout<<inorder_traversal(root, node, ans)<<endl;
    return ans;
}