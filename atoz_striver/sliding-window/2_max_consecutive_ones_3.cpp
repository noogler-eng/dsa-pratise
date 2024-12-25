// Max Consecutive Ones III
// QUESTION - https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include<iostream>
#include<vector>
using namespace std;

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// as we decide i will only change due to 0 not by 1
// 1. if k is less them 0 then make it positive
// 2. include the current one if 0 then decrese k
// 3. calculate the max length

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0;
        int max_length = 0;
        while(j < nums.size()){
            if(nums[j] == 0){
                while(k <= 0){
                    if(nums[i] == 0) k++;
                    i++;
                }
                k--;
            }
            max_length = max(max_length, j-i+1);
            j++;
        }
        return max_length;
    }
};