// QUESTION - https://leetcode.com/problems/container-with-most-water/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int maxWater = 0;
        while(start < end){
            if(height[start] <= height[end]){
                int waterTrap = height[start] * (end - start);
                maxWater = max(maxWater, waterTrap);
                start++;
            }else{
                int waterTrap = height[end] * (end - start);
                maxWater = max(maxWater, waterTrap);
                end--;
            }
        }
        return maxWater;
    }
};