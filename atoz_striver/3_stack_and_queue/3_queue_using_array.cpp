// queue using array

#include<iostream>
#include<queue>
using namespace std;

class Queue {
    public:
    vector<int> arr;
    int i = -1;
    int j = -1;
    int s = 0;
    Queue(int x){
        arr.resize(x);
    }

    void push(int ele){
        if(i >= arr.size()-1) return;
        if(j == -1) j = 0;
        arr[i+1] = ele;
        s++;
        i++;
    }

    void pop(){
        if(s == 0) return;
        s--;
        i--;
        j--;
    }

    int front(){
        if(j == -1) return;
        return arr[j];
    }

    void size(){
        if(i == -1) ;
    }

    void empty(){

    }

};