// QUESTION - https://leetcode.com/problems/daily-temperatures/description/

#include<iostream>
#include<vector>
using namespace std;

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// time complexity o(2N)
// space complexity o(N)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> next_greater(n);
        stack<int> st;
        for(int i=temperatures.size()-1; i>=0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();
            if(st.empty()){
                next_greater[i] = 0;
            }else{
                next_greater[i] = st.top() - i;
            }
            st.push(i);
        }

        return next_greater;
    }
};