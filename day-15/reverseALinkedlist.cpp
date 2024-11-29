// QUESTION - https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* future;
        while(temp!=NULL){
            future = temp->next;
            temp->next = prev;
            prev = temp;
            temp = future;
        }
        return prev;
    }
};