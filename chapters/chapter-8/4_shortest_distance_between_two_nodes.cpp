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
// step2. travese them on the both side like travelling from right as well as from left
// here we are using the true and false wheather to find that this direction contains node or not
// if not then simpley pop, if found then return not poping
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

    bool toLCA(TreeNode* root, int target, string& path){
        if (root == NULL) return false;
        if (root->val == target) return true;
        path.push_back('U');
        if (toLCA(root->left, target, path) || toLCA(root->right, target, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }


    bool findPath(TreeNode* root, int target, string& path, char direction) {
        if (!root) return false;
        path.push_back(direction);
        if (root->val == target) return true;
        if (findPath(root->left, target, path, 'L') || findPath(root->right, target, path, 'R')) {
            return true;
        }
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lowest_common_parent = helper(root, startValue, destValue);
        string path1="";
        string path2="";
        toLCA(lowest_common_parent, startValue, path1);
        findPath(lowest_common_parent, destValue, path2, '.');
        cout<<path1<<" "<<path2<<endl;

        return path1+path2.substr(1, path2.length());
    }
};

// we can aslo do this
// after this place all the L, R to U in upper string
string upper, lower;
void findingPath(TreeNode* root, int startValue, int destValue, string path){
    if(root == NULL) return;
    if(root->val == startValue) upper = path;
    if(root->val == destValue) lower = path;

    path.push_back('L');
    findingPath(root->left, startValue, destValue, path);
    path.pop_back();

    path.push_back('R');
    findingPath(root->right, startValue, destValue, path);
    path.pop_back();
}