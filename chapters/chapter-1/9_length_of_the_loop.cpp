// Find The Length Of The Loop
// QuESTION - https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop

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

int countNodesinLoop(Node *head) {
    if(head == NULL || head->next == NULL) return 0;
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    if(slow != fast) return 0;
    slow = slow->next;
    int count=1;
    while(slow!=fast){
        count++;
        slow = slow->next;
    }

    return count;

}