// Find the intersection point of Y LL
// QUESTION - https://leetcode.com/problems/intersection-of-two-linked-lists/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1!=NULL){
            len1++;
            temp1 = temp1->next;
        }

        while(temp2!=NULL){
            len2++;
            temp2 = temp2->next;
        }
        temp1 = headA;
        temp2 = headB;
        while(temp1 != NULL && len1 > len2){
            temp1 = temp1->next;
            len1--;
        }

        while(temp2 != NULL && len2 > len1){
            temp2 = temp2->next;
            len2--;
        }

        while(temp1!=NULL && temp2!=NULL){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;
    }
};