// QUESTION - https://leetcode.com/problems/find-the-duplicate-number/description/

#include<iostream>
using namespace std;

// time complexity o(2N)
// space complexity o(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // You must solve the problem without modifying the array nums and using only constant extra space.
        int n = nums.size();
        int ans = -1;
        for(int i=0; i<n; i++){
            int number = abs(nums[i]);
            if(nums[number-1] < 0) {
                ans = number;
                break;
            }
            else nums[number-1] = (nums[number-1]) / -1;
        }

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 0){
                nums[i] = nums[i] / -1;
            }
        }
        return ans;
    }
};