// QUESTION - https://leetcode.com/problems/reverse-pairs/

#include<iostream>
#include<vector>
using namespace std;

// simply double looping ....
// time limit exceed here (TLE)
// time complexity o(N*N)
// space complexity o(1)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // 1, 3, 2, 3, 1
        long long count = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(float(nums[i]) / 2.0 > float(nums[j])) count++;
            }
        }
        return count;
    }
};


