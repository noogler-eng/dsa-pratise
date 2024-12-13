// QUESTION - https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size());
        vector<int> right_max(height.size());

        int l_max = 0;
        for(int i=0; i<height.size(); i++){
            left_max[i] = l_max;
            l_max = max(l_max, height[i]);
        }
        
        int r_max = 0;
        for(int i=height.size()-1; i>=0; i--){
            right_max[i] = r_max;
            r_max = max(r_max, height[i]);
        }

        int waterTrap = 0;
        for(int i=0; i<height.size(); i++){
            if(height[i] <= left_max[i] && height[i] <= right_max[i]){
                waterTrap += min(left_max[i], right_max[i]) - height[i];
            }
        }
        return waterTrap;
    }
};