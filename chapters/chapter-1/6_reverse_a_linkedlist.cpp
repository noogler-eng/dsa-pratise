// Reverse A LinkedList
// QUESTION - https://leetcode.com/problems/reverse-linked-list/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// reversing a linkedlist iteratively
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* futr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = futr;
        }
        return prev;
    }
};

// reversing a linkedlist recurisvely
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* reverse_list = reverseList(head->next);
        head->next->next = head; 
        head->next = NULL;  
        return reverse_list;
    }
};