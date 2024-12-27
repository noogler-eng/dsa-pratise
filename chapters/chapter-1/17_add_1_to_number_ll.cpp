// Add Number 1 to Number LL
// QUESTION - https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

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

Node* reverse(Node* &head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        Node* futr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = futr;
    } 
    return prev;
}

Node* addOne(Node* head) {
    Node* temp = reverse(head);
    head = temp;
    int carry = 1;
    Node* last_node = NULL;
    while(temp!=NULL && carry > 0){
        int new_val = temp->data + carry;
        carry = new_val / 10;
        temp->data = new_val % 10;
        if(temp->next == NULL) {
            last_node = temp;
        }
        temp = temp->next;
    }

    if(carry > 0){
        last_node->next = new Node(carry);
    }

    Node* ans = reverse(head);
    return ans;
}