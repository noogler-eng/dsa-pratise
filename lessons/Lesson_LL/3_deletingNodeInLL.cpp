// QUESTION - https://leetcode.com/problems/delete-node-in-a-linked-list/description/

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
        }
};

// given node in the linkedlist is not the last one
// time complexity o(N)
// space complexity o(1)
void deleteNode(Node* node) {
    Node* temp = node;
    Node* prev = node;
    while(temp->next!=NULL){
        prev = temp;
        int next_element_data = temp->next->data;
        temp->data = next_element_data;
        temp = temp->next;
    }
    prev->next = NULL;
}

int main(){

}