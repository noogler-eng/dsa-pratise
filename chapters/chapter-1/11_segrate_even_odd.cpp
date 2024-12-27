// Segrate Odd And Even In LinkedList
// QUESTION - https://leetcode.com/problems/odd-even-linked-list/description/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* evenStart = head->next;
        ListNode* even = head->next;
        while(odd!=NULL && even!=NULL && even->next!=NULL && odd->next!=NULL){
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even ->next->next;
            even = even->next;
        }
        odd->next = evenStart;
        return head;
    }
};