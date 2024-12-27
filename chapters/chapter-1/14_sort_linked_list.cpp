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

// Merge Sort with Time Complexity o(NLogN)
