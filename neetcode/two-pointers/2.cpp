// QUESTION - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Your solution must use only constant extra space.
        // You may not use the same element twice
        int start = 0;
        int end = numbers.size()-1;
        vector<int> ans;
        while(start < end){
            if(numbers[start] + numbers[end] == target){
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                return ans;
            }else if(numbers[start] + numbers[end] < target){
                start = start + 1;
            }else {
                end = end - 1;
            }
        }
        return ans;
    }
};