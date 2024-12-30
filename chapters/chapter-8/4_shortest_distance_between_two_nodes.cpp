// Step By Step Directions From a Binary Tree Node To Another
// QUESTION - https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/

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

// we have to find the shortest path between startValue and destValue
// all this are the nodes
// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.

// step1. finding the lowest parent of them
// step2. 
class Solution {
public:

    TreeNode* helper(TreeNode* root, int startValue, int destValue){
        if(root == NULL || root->val == startValue || root->val == destValue) return root;

        TreeNode* left = helper(root->left, startValue, destValue);
        TreeNode* right = helper(root->right, startValue, destValue);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
    }

    bool findPath(TreeNode* root, int target, string& path, char direction) {
        if (!root) return false;
        if (root->val == target) return true;
        path.push_back(direction);
        if (findPath(root->left, target, path, 'L') || findPath(root->right, target, path, 'R')) {
            return true;
        }
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lowest_common_parent = helper(root, startValue, destValue);
        string ans="";

        findPath(root, startValue, ans, 'U');
        findPath(root, destValue, ans, '\0');
        return ans;
    }
};