// QUESTION - https://leetcode.com/problems/next-permutation/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int point = -1;
        // move until the farthest
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                point = i;
                break;
            }
        }
        
        if(point != -1){
            int mini = INT_MAX;
            int miniIndex = point;
            for(int i=point+1; i<nums.size(); i++){
                if(nums[i] < mini && nums[i] > nums[point]){
                    mini = nums[i];
                    miniIndex = i;
                }
            }
            cout<<point<<" "<<miniIndex<<endl;
            swap(nums[point], nums[miniIndex]);
        }

        sort(nums.begin() + point + 1, nums.end());
    }
};