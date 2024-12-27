// Sort 0, 1, 2s In The LinkedList
// QUESTION - https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next = NULL;
    Node(int x){
        this->data = x;
    }
};

// time complexity o(2N)
// space complexity o(1)
Node* segregate1(Node* head) {
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }

    temp = head;
    while(cnt0 > 0){
        temp->data = 0;
        cnt0--;
        temp = temp->next;
    }

    while(cnt1 > 0){
        temp->data = 1;
        cnt1--;
        temp = temp->next;
    }

    while(cnt2 > 0){
        temp->data = 2;
        cnt2--;
        temp = temp->next;
    }

    return head;
}

// we can also do this in one go 
Node* segregate(Node* head) {
    Node* zero = new Node(-1);
    Node* zeroStart = zero;
    Node* one = new Node(-1);
    Node* oneStart = one;
    Node* two = new Node(-1);
    Node* twoStart = two;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0) {
            zero->next = new Node(0);
            zero = zero->next;
        }
        else if(temp->data == 1) {
            one->next = new Node(1);
            one = one->next;
        }
        else {
            two->next = new Node(2);
            two = two->next;
        }
        temp = temp->next;
    }
    
    Node* dummy = new Node(-1);
    Node* ans = dummy;
    
    if(zeroStart->next!=NULL) {
        dummy->next = zeroStart->next;
        dummy = zero;
    };
    if(oneStart->next != NULL) {
        dummy->next = oneStart->next;
        dummy = one;
    }
    
    if(twoStart->next != NULL) {
        dummy->next = twoStart->next;
    }
    return ans->next;
}