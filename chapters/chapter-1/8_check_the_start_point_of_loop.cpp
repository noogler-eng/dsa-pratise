// Detect A Loop In Linkedlist
// QUESTION - https://leetcode.com/problems/linked-list-cycle-ii/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// fast will travel 2x as total distance while slow will x so the distance conver remaing is x from both side
// moving both x, here type of we are mathing them at the middle node then travelling
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }   

        if(slow!=fast) return NULL;

        fast = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};