// Cnverted Sorted List To Binary Search Tree
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

// time complexity o(logN)
// space complity o(1)
class Solution {
public:
    // this is how we find the middle of the linkedlist
    // slow and fast pointer method
    // fast travel by 2x while slow travel by x
    // so here x is the middle
    ListNode* getMiddle(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(!prev == NULL){
            prev->next = NULL;
        }
        return slow;
    }

    TreeNode* helper(ListNode* head){
        if(head == NULL) return NULL;
        ListNode* middle = getMiddle(head);
        TreeNode* bt = new TreeNode(middle->val);

        // if there is only a single node then
        if(head == middle) return bt;

        bt->left = helper(head);
        bt->right = helper(middle->next);
        return bt;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* bt = helper(head);
        return bt;
    }
};

TreeNode* convertListToBst(ListNode* start, ListNode* end){
    if(start == end) return NULL;
    ListNode* slow = start;
    ListNode* fast = start;

    // moving slow and fast
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    TreeNode* head = new TreeNode(slow->val);
    head->left = convertListToBst(start, slow);
    head->right = convertListToBst(slow->next, end);
    return head;
}

TreeNode* sort(ListNode* head){
    if(head == NULL) return NULL;
    return convertListToBst(head, NULL);
}