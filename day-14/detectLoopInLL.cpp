// QUESTION - https://leetcode.com/problems/linked-list-cycle/

#include<iostream>
using namespace std;

class ListNode {
    public: 
        int val;
        ListNode* next;
        ListNode(int val){
            this->val = val;
            this->next = NULL;
        }
};

// time complexity o(N)
// space complexity o(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};