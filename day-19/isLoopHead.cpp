// QUESTION LINK: https://leetcode.com/problems/linked-list-cycle-ii/

#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// time compelxity o(2N)
// space complexity o(1)
// optmized approach
Node* is_loop_return_head(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    int isloopExists = false;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            isloopExists = true;
            break;
        }
    }

    if(!isloopExists) return NULL;
    fast = head;
    while(fast!=slow){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// brute force approach, wherever we find the exact same node return
// time complexity o(N)
// space complexity o(N)
Node* is_loop_return_head_b(Node* head){
    unordered_map<Node*, int> m;
    Node* temp = head;
    while(temp != NULL){
        if(m.find(temp) != m.end()){
            return temp;
        }else{
            m[temp] = 1;
            temp = temp->next;
        }
    }
    return NULL;
}


int main(){
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-1);
    head->next->next->next->next = head->next;
    Node* ans_1 = is_loop_return_head(head);
    Node* ans_2 = is_loop_return_head_b(head);

    if(ans_1 != NULL) cout<<ans_1->data<<endl;
    if(ans_2 != NULL) cout<<ans_2->data<<endl;
    return 0;
}