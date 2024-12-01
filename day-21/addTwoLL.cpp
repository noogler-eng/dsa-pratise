// QUESTION - https://leetcode.com/problems/add-two-numbers/

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

// Optmized version
// time complexity o(3N)
// space complxity o(1)
class Solution {
public:
    int length(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // lengths
        int len1 = length(l1);
        int len2 = length(l2);

        ListNode* temp;
        ListNode* head;
        if(len1 > len2) temp = l1;
        else temp = l2;
        head = temp;

        int carry = 0;
        ListNode* prev = temp;
        while(l1!=NULL && l2!=NULL){
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            int value = sum % 10;
            temp->val = value;
            prev = temp;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }


        while(l1!=NULL){
            int sum = l1->val + carry;
            carry = sum / 10;
            int value = sum % 10;
            temp->val = value;
            prev = temp;
            temp = temp->next;
            l1 = l1->next;
        }

        while(l2!=NULL){
            int sum = l2->val + carry;
            carry = sum / 10;
            int value = sum % 10;
            temp->val = value;
            prev = temp;
            temp = temp->next;
            l2 = l2->next;
        }

        if(carry > 0) prev->next = new ListNode(carry);
        return head;
    }
};