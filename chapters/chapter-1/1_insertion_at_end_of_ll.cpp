// 1. Insertion Of Node At The End Of Linkedlist
// QUESTION - https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion

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

Node *insertAtEnd(Node *head, int x) {
    Node* temp = head;
    Node* new_node = new Node(x);

    if( head == NULL ) return new_node;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = new_node;
    return head;
}