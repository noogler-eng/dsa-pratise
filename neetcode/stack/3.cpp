// QUESTION - https://leetcode.com/problems/daily-temperatures/ 

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1; i >= 0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();
            if(st.empty() == true) ans[i] = 0;
            else ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};