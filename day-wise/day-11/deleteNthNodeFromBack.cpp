// QUESTION - https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/1466258542/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        int length_of_ll = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            length_of_ll++;
            temp = temp->next;
        }

        int deletionNode = length_of_ll - n + 1;
        if(deletionNode == 1) return head->next;

        ListNode* prev;
        ListNode* new_temp = head;
        int len = 0;
        while(len < deletionNode - 1){
            len++;
            prev = new_temp;
            new_temp = new_temp->next;
        }

        prev->next = new_temp->next;
        new_temp->next = NULL;
        return head;
    }
};