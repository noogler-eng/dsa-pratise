// QUESTION - https://leetcode.com/problems/min-stack/description/

#include<iostream>
using namespace std;

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// time complexity o(1)
// space complexity o(N)
class MinStack {
public:
    vector<pair<int, int>> v;
    int topp = -1;

    MinStack() {}
    
    void push(int val) {
        if(topp > -1){
            int mini = v[topp].second;
            if(val < mini){
                v.push_back({val, val});
            }else{
                v.push_back({val, mini});
            }
        }else{
            v.push_back({val, val});
        }
        topp++;
    }
    
    void pop() {
        if(topp > -1){
            v.pop_back();
            topp--;
        }
    }
    
    int top() {
        if(topp > -1){
            return v[topp].first;
        }
        return NULL;
    }
    
    int getMin() {
        if(topp > -1){
            return v[topp].second;
        }
        return NULL;
    }
};
