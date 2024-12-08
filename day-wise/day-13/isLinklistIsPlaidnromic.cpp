// QUESTION - https://leetcode.com/problems/palindrome-linked-list/

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

// time complexity o(2N)
// space complexity o(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s = "";
        ListNode* temp = head;
        while(temp!=NULL){
            s+=temp->val;
            temp = temp->next;
        }

        int start = 0;
        int end = s.length()-1;
        while(start < end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }

        return true;
    }
};