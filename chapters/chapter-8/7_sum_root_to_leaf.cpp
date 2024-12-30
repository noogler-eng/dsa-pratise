// Sum Of Root To Leaf
// QUESTION - https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// recursive soltion
// time complexity o(N)
// space complexity O(1)
class Solution {
public:
    void helper(TreeNode* root, int &sum, int value){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            value = value * 10 + root->val;
            sum+=value;
            return;
        }

        value = value * 10 + root->val;
        helper(root->left, sum, value);
        helper(root->right, sum, value);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, sum, 0);
        return sum;
    }
};

// iterative way
// time complexity o(N)
// space complexity o(N)
class Solution {
public:
    int sumNumbers(TreeNode* root){
        if(root == NULL) return;
        queue<pair<TreeNode*, int>> q;
        int sum = 0;
        q.push({root, 0});
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int value = q.front().second;

            int new_value = value + node->val;
            if(node->left == NULL && node->right == NULL) sum+=new_value;
            if(node->left!=NULL) sumNumbers(node->left);
            if(node->right!=NULL) sumNumbers(node->right);
        }
        return sum;
    }
};