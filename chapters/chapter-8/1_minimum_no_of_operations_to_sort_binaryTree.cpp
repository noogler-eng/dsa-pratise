// Minimum No Of Operatios To Sort BinaryTree
// QUESTION - https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
#include<iostream>
#include<queue>
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

// In one operation, you can choose any two nodes at the same level and swap their values.
// In one operation, you can choose any two nodes at the same level and swap their values.
// Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
// The level of a node is the number of edges along the path between it and the root node.

class Solution {
public:
    int countSwaps(vector<int> values){
        int swaps = 0;
        unordered_map<int, int> m;
        vector<int> sorted = values;
        for(int i=0; i<values.size(); i++) m[values[i]] = i;
        sort(sorted.begin(), sorted.end());
        
        for(int i=0; i<values.size(); i++) {
            if(sorted[i] != values[i]){
                int v = m[sorted[i]];
                m[values[i]] = v;
                m[sorted[i]] = i;
                swap(values[i], values[v]);
                swaps++;
            }
        }
        return swaps;
    }

    // this is how we travers the binary tree (BFS)
    int minimumOperations(TreeNode* root) {
        // for each we have to make the minimum no of swapps for sorting
        // if minimum swaps then think of what can be maximum swapp.., sapping in each 
        queue<TreeNode*> q;
        q.push(root);
        int swaps = 0;
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }

            // map contains unsorted element index
            swaps+=countSwaps(level);
        }
        return swaps;

    }
};