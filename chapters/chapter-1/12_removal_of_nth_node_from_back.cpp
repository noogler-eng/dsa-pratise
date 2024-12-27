// Remove The Nth Node From The Back
// QUESTION - https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* temp = head;
        int total = 0;
        while(temp!=NULL){
            total++;
            temp = temp->next;
        }

        cout<<total<<endl;

        temp = head;
        int count_travel = total - n;
        if(count_travel == 0) return head->next;
        while(count_travel > 1){
            count_travel--;
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return head;
    }
};