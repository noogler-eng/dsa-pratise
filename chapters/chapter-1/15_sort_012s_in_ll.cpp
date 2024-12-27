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
Node* segregate(Node* head) {
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