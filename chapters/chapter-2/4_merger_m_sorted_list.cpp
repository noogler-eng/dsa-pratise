// Merger M Sorted List
// QUESTION - https://leetcode.com/problems/merge-k-sorted-lists/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(-1);
        ListNode* ansStart = ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp!=NULL){
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        while(!pq.empty()){
            ListNode* new_node = new ListNode(pq.top());
            pq.pop();
            ans->next = new_node;
            ans = new_node;
        }

        return ansStart->next;
    }
};