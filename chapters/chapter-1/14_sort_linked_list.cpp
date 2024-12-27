// Sort The LinkedList
// QUESTION - https://leetcode.com/problems/sort-list/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// this show the Time Limit Exceed
class Solution {
public:

    void sortStack(stack<int> &st, int value){
        if(st.size() == 0 || st.top() < value) {
            st.push(value);
            return;
        }
        int ele = st.top();
        st.pop();
        sortStack(st, value);
        st.push(ele);
    }

    void helper(ListNode* head, stack<int> st){
        if(head == NULL) return;
        sortStack(st, head->val);
        helper(head->next, st);
        head->val = st.top();
        st.pop();
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        stack<int> st;
        helper(head, st);
        return head;
    }
};

// this is brute force solution 
// this solution takes the time complexity o(N + N + NlogN)
// space complexity o(N)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }

        // basically this is merge sort
        sort(v.begin(), v.end());
        temp = head;
        int i=0;
        while(temp!=NULL){
            temp->val = v[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};

// Merge Sort with Time Complexity o(NLogN)
// always remember the merge sort code snippets
// void merge_sort(arr, low, high){
//     if(low == high) return;
//     int mid = (low + high ) / 2;
//     merge_sort(arr, low, mid);
//     merge_sort(arr, mid+1, high);
//     merge(arr, low, mid, high);
// }
class Solution {
public:
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // this is how we merger two sorted linkedlist
    ListNode* merge(ListNode* leftHead, ListNode* rightHead) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (leftHead != NULL && rightHead != NULL) {
            if (leftHead->val < rightHead->val) {
                temp->next = leftHead;
                leftHead = leftHead->next;
            } else {
                temp->next = rightHead;
                rightHead = rightHead->next;
            }
            temp = temp->next;
        }

        if (leftHead != NULL) {
            temp->next = leftHead;
        }

        if (rightHead != NULL) {
            temp->next = rightHead;
        }

        return dummy->next;
    }

    ListNode* merge_sort(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* middle_node = getMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle_node->next;
        middle_node->next = NULL;

        leftHead = merge_sort(leftHead);
        rightHead = merge_sort(rightHead);

        return merge(leftHead, rightHead);
    }

    ListNode* sortList(ListNode* head) { return merge_sort(head); }
};