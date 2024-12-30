// No Of Good Leaf Nodes Pairs
// QUESTION - https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/

// You are given the root of a binary tree and an integer distance. 
// A pair of two different leaf nodes of a binary tree is said to be good 
// if the length of the shortest path between them is less than or equal to 
// distance.

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
    int countPairs(TreeNode* root, int distance) {
        // it is question of the shortest distance between two nodes
        
    }
};