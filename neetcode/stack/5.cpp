//QUESTION - https://leetcode.com/problems/largest-rectangle-in-histogram/

#include<iostream>
#include<vector>
using namespace std;

// time limit exceed o(N*N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = INT_MIN;
        for(int i=0; i<heights.size(); i++){
            int minHeight = INT_MAX;
            for(int j=i; j<heights.size(); j++){
                minHeight = min(minHeight, heights[j]);
                area = max(area, minHeight * (j-i+1));
            }
        }
        return area;
    }
};

// optimal solution -
// usage of the stack
class Solution {
public:
    void getNse(vector<int> heights, vector<int> &nse){
        stack<int> st;
        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty() == true) nse[i] = heights.size();
            else nse[i] = st.top();
            st.push(i);
        }
    }

    void getPse(vector<int> heights, vector<int> &pse){
        stack<int> st;
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty() == true) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        vector<int> pse(n);

        getNse(heights, nse);
        getPse(heights, pse);

        int maxArea = 0;
        for(int i=0; i<heights.size(); i++){
            int left = pse[i];
            int right = nse[i];
            int width = right - left - 1;
            maxArea = max(maxArea, width * heights[i]);
        }

        return maxArea;
    }
};