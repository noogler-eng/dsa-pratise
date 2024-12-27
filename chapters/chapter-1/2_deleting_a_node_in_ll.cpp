// Delete Node In LinkedList
// QUESTION - https://leetcode.com/problems/delete-node-in-a-linked-list/

// 1. we can either dleete from first, from middle, from last
// 2. You will not be given access to the first node of head.
// 3. move until the last node by swapping and detach last node
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        ListNode* forward = temp->next;
        if(forward == NULL) {
            temp = NULL;
            return;
        }

        // 4, 5, 1, 9, null
        // t, t, t, f, f
        while(forward->next!=NULL){
            temp->val = forward->val;
            temp = forward;
            forward = forward->next;
        }

        temp->val = forward->val;
        temp->next = NULL;
    }
};