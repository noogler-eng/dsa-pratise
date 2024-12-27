// Find The Length Of LinkedList
// QUESTION - https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-nodes-of-linked-list

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

int getCount(struct Node* head) {
    Node* temp = head;
    if(temp == NULL) return 0;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
