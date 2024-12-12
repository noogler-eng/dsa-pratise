// QUESTION - https://leetcode.com/problems/min-stack/

#include<iostream>
#include<vector>
using namespace std;

class MinStack {
public:
    vector<pair<int, int>> s;
    int index = -1;
    MinStack() {}
    
    void push(int val) {
        if(s.size() == 0){
            s.push_back({val, val});
        }else{
            int mini = min(s[s.size()-1].second, val);
            s.push_back({val, mini});
        }
        index++;
    }
    
    void pop() {
        if(s.size() == 0 || index == -1) return;
        else {
            s.pop_back();
            index--;
        }
    }
    
    int top() {
        if(s.size() == 0 || index == -1) return -1;
        else return s[index].first;
    }
    
    int getMin() {  
         if(s.size() == 0 || index == -1) return -1;
        else return s[index].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */