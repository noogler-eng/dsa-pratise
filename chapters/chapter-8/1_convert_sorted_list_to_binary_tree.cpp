// Cnverted Sorted List To Binary Tree
// QUESTION - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
// height-balanced - means balance height on both the side

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    // this is how we find the middle of the linkedlist
    // slow and fast pointer method
    //  fast travel by 2x while slow travel by x
    // so here x is the middle
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void addNodeToTree(TreeNode* &tree ,ListNode* node){
        if(tree->left == NULL && node->val < tree->val) {
            TreeNode* bt = new TreeNode(node->val);
            tree->left = bt;
            return;
        }
        
        if(tree->val < node->val) return addNodeToTree(tree->right, node);
        if(tree->val > node->val) return addNodeToTree(tree->left, node);
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* findMiddle = getMiddle(head);
        TreeNode* bt = new TreeNode(findMiddle->val);
        ListNode* left = head;
        ListNode* right = findMiddle->next;
        findMiddle->next = NULL;
        
        // my left subtree is from head to middle
        // my right subtree is from middle to end
        while(left!=NULL){
            if(left == findMiddle) break;
            addNodeToTree(bt, left);
            left = left->next;
        }

        while(right!=NULL){
            addNodeToTree(bt, right);
            right = right->next;
        }
        
        return bt;
    }
};