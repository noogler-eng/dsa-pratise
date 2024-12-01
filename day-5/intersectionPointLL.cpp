// QUESTION - https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/1467543078/

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

// optmized version, there can also be slow and fast pointer method
// time complexity o(2N + 2M)
// space complexity o(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;

        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA!=NULL){
            len1++;
            tempA = tempA->next;
        }

        while(tempB!=NULL){
            len2++;
            tempB=tempB->next;
        }

        tempA = headA;
        tempB = headB;

        while(len1 > len2){
            tempA = tempA->next;
            len1--;
        }

        while(len2 > len1){
            tempB = tempB->next;
            len2--;
        }

        while(tempA!=NULL && tempB!=NULL){
            if(tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL;
    }
};