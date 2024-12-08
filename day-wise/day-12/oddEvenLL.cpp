// QUESTION - https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* even_start = head->next;
        ListNode* temp_even = head->next;
        ListNode* temp_odd = head;
        ListNode* odd_end;
        
        while (temp_even != NULL && temp_even->next != NULL) {
            temp_odd->next = temp_odd->next->next;
            temp_odd = temp_odd->next;

            temp_even->next = temp_even->next->next;
            temp_even = temp_even->next;
        }

        temp_odd->next = even_start;
        return head;
    }
};