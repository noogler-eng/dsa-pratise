// QUESTION - https://leetcode.com/problems/largest-rectangle-in-histogram/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// stand at a point and see the nearmost minimum so that it the distance between them is width
// 4 5 6 5 3
// here the nearmost minimum for 5 is 4 and 3 so between them is constant space
// time complxity o(5N) ~ o(N)
// space complexity o(3N) ~ o(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSideFirstLower(n);
        vector<int> rightSideFirstLower(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()){
                leftSideFirstLower[i] = -1;
            }else{
                leftSideFirstLower[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()){
                rightSideFirstLower[i] = n;
            }else{
                rightSideFirstLower[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = 0;
        for(int i=0; i<n; i++){
            int left = leftSideFirstLower[i];
            int right = rightSideFirstLower[i];
            int width = right - left - 1;
            maxArea = max(maxArea, width * heights[i]);
        }

        return maxArea;
    }
};