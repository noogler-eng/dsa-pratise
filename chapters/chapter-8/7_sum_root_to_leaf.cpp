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