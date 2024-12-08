// QUESTION - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* temp = head;
        int length_of_ll = 0;
        while(temp!=NULL){
            length_of_ll++;
            temp = temp->next;
        }

        int middleNode = floor(double(length_of_ll) / double(2)) + 1;
        if(middleNode == 1) return head->next;

        ListNode* new_temp = head;
        ListNode* prev;
        int len = 0;
        while(len < middleNode-1){
            len++;
            prev = new_temp;
            new_temp = new_temp->next;
        }
        prev->next = new_temp->next;
        new_temp->next = NULL;
        return head;
    }
};