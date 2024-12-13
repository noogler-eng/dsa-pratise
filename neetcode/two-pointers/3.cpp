// QUESTION - https://leetcode.com/problems/3sum/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        
        for(int i=0; i<nums.size()-1; i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int start = i+1;
            int end = nums.size()-1;
            int sum = nums[i];
            while(start < end){
                if(sum + nums[start] + nums[end] == 0){
                    vector<int> ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[start]);
                    ans.push_back(nums[end]);
                    s.insert(ans);
                    start = start+1;
                }else if(sum + nums[start] + nums[end] < 0){
                    start = start + 1;
                }else {
                    end = end - 1;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto i: s){
            ans.push_back(i);
        }
        return ans;
    }
};