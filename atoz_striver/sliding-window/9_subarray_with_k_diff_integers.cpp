// Subarray with k different integers
// QUESTION - https://leetcode.com/problems/subarrays-with-k-different-integers/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, int k){
        int i=0, j=0;
        int count = 0;
        unordered_map<int, int> m;
        while(j < nums.size()){
            m[nums[j]]++;
            while(m.size() > k){
                m[nums[i]]--;
                if(m[nums[i]] == 0) m.erase(nums[i]);
                i++;
            }
            if(m.size() <= k){
                count+=j-i+1;
            }
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};