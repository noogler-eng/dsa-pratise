// QUESTION - https://leetcode.com/problems/sort-colors/
#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else {
                swap(nums[mid], nums[high]);
                high--;
            }   
        }
    }
};