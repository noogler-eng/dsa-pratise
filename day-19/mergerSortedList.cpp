// QUESTION - https://leetcode.com/problems/merge-two-sorted-lists/

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

// Time complexity o(N+M)
// space complxity o(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        ListNode* head = list1;
        ListNode* prev = NULL;
        while(list1!=NULL && list2!=NULL){
            if(list1->val > list2->val){
                ListNode* currentNode = list2;
                list2 = list2->next;
                currentNode->next = NULL;
                if(prev == NULL) {
                    currentNode->next = list1;
                    head = currentNode;
                    prev = currentNode;
                    list1 = currentNode->next;
                    continue;
                }
                prev->next = currentNode;
                currentNode->next = list1;
                prev=currentNode;
            }else{
                prev = list1;
                list1 = list1->next;
            }
        }

        if(list2 != NULL) {
            prev->next = list2;
        }

        return head;
    }
};