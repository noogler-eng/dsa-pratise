// QUESTION - https://leetcode.com/problems/longest-consecutive-sequence/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(NlogN) + o(N)
// space complexity o(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int count = 1;
        int ans = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
                count++;
            }else if(nums[i] == nums[i-1]){
                continue;
            }else{
                count = 1;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};