// Count number of nice subarrays
// QUESTION - https://leetcode.com/problems/count-number-of-nice-subarrays/

#include<iostream>
#include<vector>
using namespace std;

// principle of (sum < k) - (sum < k-1) gets us the no of subarray with sum k
class Solution {
public:
    int helper(vector<int>& nums, int k){
        int i=0, j=0;
        int odd_count = 0;
        int count = 0;
        while(j<nums.size()){ 
            if(nums[j] % 2 == 1) odd_count++;
            while(odd_count > k){
                if(nums[i] % 2 == 1) odd_count--;
                i++;
            }

            if(odd_count <= k){
                count+=(j-i+1);
            }
            j++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};