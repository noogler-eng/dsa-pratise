// https://leetcode.com/problems/contains-duplicate/

#include<iostream>
#include<set>
#include<vector>
using namespace std;

// time complexity o(N) and space complexity o(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }

        if(s.size() < nums.size()) return true;
        return false;
    }
};

// time complexity o(NlogN) and space complexity o(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};