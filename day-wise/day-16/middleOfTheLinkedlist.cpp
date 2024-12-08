// QUESTION - https://leetcode.com/problems/middle-of-the-linked-list/description/

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

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow!=NULL && slow->next!=NULL && fast!= NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }   
};