// QUESTION - https://leetcode.com/problems/majority-element/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // there must be only one majority element
        int majorElement = -1;
        int majorElementCount = 0;
        int i=0;
        while(i < nums.size()){
            if(majorElement == -1){
                majorElement = nums[i];
                majorElementCount++;
            }else if(majorElement == nums[i]){
                majorElementCount++;
            }else if(majorElement != nums[i]){
                if(majorElementCount > 0){
                    majorElementCount--;
                }else{
                    majorElement = nums[i];
                    majorElementCount++;
                }
            }
            i++;
        }
        return majorElement;
    }
};