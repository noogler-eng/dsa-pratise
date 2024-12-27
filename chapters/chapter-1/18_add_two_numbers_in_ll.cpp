// Add Two Numbers In LL
// QUESTION - https://leetcode.com/problems/add-two-numbers/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int len1 = 0;
        int len2 = 0;
        while(temp1!=NULL){
            len1++;
            temp1 = temp1->next;
        }

        while(temp2!=NULL){
            len2++;
            temp2 = temp2->next;
        }

        ListNode* first;
        ListNode* second;
        if(len1 >= len2){
            first = l1;
            second = l2;
        }else{
            first = l2;
            second = l1;
        }

        int carry = 0;
        ListNode* lastNode;
        ListNode* ans = first;
        while(second!=NULL){
            int value = first->val + second->val + carry;
            first->val = value % 10;
            carry = value / 10;
            if(first->next == NULL) lastNode = first;
            first = first->next;
            second = second->next;
        }

        while(carry > 0 && first!=NULL){
            int value = first->val + carry;
            first->val = value % 10;
            carry = value / 10;
            if(first->next == NULL) lastNode = first;
            first = first->next;
        }

        if(carry > 0){
            lastNode->next = new ListNode(carry);
        }

        return ans;
    }
};