// https://leetcode.com/problems/linked-list-random-node/

#include<iostream>
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

class Solution{
    public: 
        Node* root = NULL;
        int length;
        Solution(Node* root){
            this->root = root;
            this->length = this->getLength();
        }

        int getLength(){
            Node* temp = root;
            int length = 0;
            while(temp!=NULL){
                temp = temp->next;
                length++;
            }
            cout<<length<<endl;
            return length;
        }

        int getRandom(){
            int randomNo = rand() % length;
            int count = 0;
            Node* temp = root;
            while(temp!=NULL){
                if(count == randomNo) {
                    return temp->data;
                }
                temp = temp->next;
                count++;
            }
            return -1;
        }
};

int main(){
    Node* root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    Solution s(root);
    cout<<s.getRandom()<<endl;
    return 0;
}