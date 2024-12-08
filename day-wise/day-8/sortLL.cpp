// QUESTION - https://leetcode.com/problems/sort-list/submissions/1466637411/
#include<iostream>
#include<vector>
using namespace std;

// important question 
class Node{
    public:
        int data;
        Node* next;
        Node(int x){
            this->data = x;
            this->next = NULL;
        }
};

// brute force approach
// time complexity o(2N + NlogN)
// space complexity o(2N)
Node* sort_linked_list(Node* head){
    vector<int> v;
    Node* temp = head;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp = temp->next;
    }

    sort(v.begin(), v.end());
    Node* new_head = new Node(v[0]);
    Node* end = new_head;
    for(int i=1; i<v.size(); i++){
        Node* t = new Node(v[i]);
        end->next = t;
        end = t;
    }
    return new_head;
}

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}   

Node* merge(Node* left, Node* right){

    Node* dummy = new Node(0);
    Node* temp = dummy;
    while(left!=NULL && right!=NULL){
        if(left->data <= right->data){
            temp->next = left;
            left = left->next;
        }else{
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    if(left!=NULL) temp->next = left;
    if(right!=NULL) temp->next = right;

    return dummy->next;
}

// sorting using merge sort
// break into half parts
// join according to the small or bigger
// in recurssion left part executed first
Node* sort_linked_list_o(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* mid = getMid(head);
    Node* l = head;
    Node* r = mid->next;
    mid->next = NULL;
    Node* left = sort_linked_list_o(head);
    Node* right = sort_linked_list_o(mid);
    return merge(left, right);
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(5);
    Node* sorted_ll = sort_linked_list(head);
    print(sorted_ll);
    Node* sorted_ll_o = sort_linked_list_o(head);
    print(sorted_ll_o);
    return 0;
}