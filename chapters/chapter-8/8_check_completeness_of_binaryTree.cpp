// Check Completeness Of Binary Tree
// QUESTION - https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

#include<iostream>
using namespace std;

// In a complete binary tree, every level, except possibly the last, is completely filled, 
// and all nodes in the last level are as far left as possible. It can have between 1 and 2h 
// nodes inclusive at the last level h.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// simple intiution
// there must be no null node comes before the any node
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        bool isAlreadyANullNodeEncountered = false;
        while(!q.empty()){
            int size = q.size();
            cout<<size<<endl;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node == NULL) {
                    isAlreadyANullNodeEncountered = true;
                    continue;
                }

                if(isAlreadyANullNodeEncountered && node != NULL) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};