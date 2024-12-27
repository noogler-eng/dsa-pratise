// stack usign array 
#include<iostream>
#include<vector>
using namespace std;

class Stack {
    public:
    vector<int> arr;
    int i = -1;
    Stack(int x){
        arr.resize(x);
    }
    
    void push(int ele){
        if(i >= arr.size()-1) return;
        arr[i+1] = ele;
        i++;
    }

    void pop(){
        if(i <= -1) return;
        i--;
    }

    int top(){
        if(i <= -1) return;
        return arr[i];
    }

    bool empty(){
        if(i == -1) return true;
        return false;
    }
};