// Binary subarray with sum
// QUESTION - https://leetcode.com/problems/binary-subarrays-with-sum/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// first we making an prefix and chekcing
// if prefix - goal exists or not
// if exists then count

// {1, 0, 1, 0, 1}
// {0, 1, 1, 2, 2, 3}
// here 3 - goal = 1 exists 2 time counted
// here 2 - goal = 0 exists 1 time counted as 2 for 2 times 2
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m;
        int count = 0;
        int prefix = 0;
        m[prefix] = 1;
        for(int i=0; i<nums.size(); i++){
            prefix += nums[i];
            int value = prefix - goal;
            if(m.find(value)!=m.end()){
                count+=m[value];
            }
            m[prefix]++;
        }
        return count;
    }
};