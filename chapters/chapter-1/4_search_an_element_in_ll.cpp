// Search Element In LL
// QUESTION - https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-linked-list-1664434326

#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next = NULL;
    Node(int x){
        this->data = x;
    }
};

bool searchKey(int n, Node* head, int key) {
    Node* temp = head;
    if(temp == NULL) return false;
    while(temp!=NULL){
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}
