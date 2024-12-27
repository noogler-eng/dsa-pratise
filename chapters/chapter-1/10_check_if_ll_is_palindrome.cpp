// Check If The Linklist Is Palindrome Or Not
// QUESTION - https://leetcode.com/problems/palindrome-linked-list/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// constraints: 
// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        string s = "";
        ListNode* temp = head;
        while(temp!=NULL){
            s += temp->val + '0';
            temp = temp->next;
        }

        int start = 0;
        int end = s.length()-1;
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }

        return true;
    }
};