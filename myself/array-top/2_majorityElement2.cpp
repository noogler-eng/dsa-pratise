// QUESTION - https://leetcode.com/problems/majority-element-ii/

#include<iostream>
using namespace std;

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // at max there must be 2 majority element
        int major1 = -1;
        int major1Count = 0;
        int major2 = -1;
        int major2Count = 0;

        int i=0;
        while(i < nums.size()){
            if(major1Count == 0 && nums[i] != major2){
                major1 = nums[i];
                major1Count = 1;
            }else if(major2Count == 0 && nums[i] != major1){
                major2 = nums[i];
                major2Count = 1;
            }else if(major1 == nums[i]){
                major1Count++;
            }else if(major2 == nums[i]){
                major2Count++;
            }else{
                major1Count--;
                major2Count--;
            }
            i++;
        }

        vector<int> ans;
        major1Count = 0;
        // checking for major1
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == major1) major1Count++;
        }
        if(major1Count > nums.size() / 3) ans.push_back(major1);

        major2Count = 0;
        // checking for major1
        if(major1 != major2){
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == major2) major2Count++;
            }
            if(major2Count > nums.size() / 3) ans.push_back(major2);
        }

        return ans;
    }
};