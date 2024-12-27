// Middle Of The LinkedList
// QUESTION - https://leetcode.com/problems/middle-of-the-linked-list/description/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        // 1, 2, 3, 4, 5
        // 1, 2, 3, 4, 5, 6

        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};