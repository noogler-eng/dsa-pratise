// https://leetcode.com/problems/binary-search/description/

#include<iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
};