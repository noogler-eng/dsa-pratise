// Reverse Odd Level Of Binary Tree
// QUESTION - https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // odd levels meaning level with 1, 3, 5, ...
    vector<vector<TreeNode*>> reversedLevels;
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> odd_level;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(level % 2 != 0){
                    odd_level.push_back(node);
                }

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            if(level % 2 != 0) reversedLevels.push_back(odd_level);
            level++;
        }

        // swapping only thr value as due to refrencing it will be swapped in original one
        for(int i=0; i<reversedLevels.size(); i++){
            int start = 0;
            int end = reversedLevels[i].size()-1;
            while(start <= end){
                swap(reversedLevels[i][start]->val, reversedLevels[i][end]->val);
                start++;
                end--;
            }
        }
        
        return root;
    }
};

// any perfect binary tree has all the complete nodes at the last level

// we can also apply the dfs for this 
class Solution {
public:
    void dfs(TreeNode* leftChild, TreeNode* rightChild, int currentLevel) {
        if (leftChild == NULL || rightChild == NULL)
            return;
        // here we considering even postions as we dont take root;s level as 0 
        // we directly starting from even
        if (currentLevel % 2 == 0) {
            swap(leftChild->val, rightChild->val);
        }

        dfs(leftChild->left, rightChild->right, currentLevel + 1);
        dfs(leftChild->right, rightChild->left, currentLevel + 1);
    }
    // odd levels meaning level with 1, 3, 5, ...
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 0);
        return root;
    }
};
