// The Number Of Beautiful Subsets
// QUESTION - https://leetcode.com/problems/the-number-of-beautiful-subsets/description/

#include<iostream>
using namespace std;

// You are given an array nums of positive integers and a positive integer k.
// A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k
// Return the number of non-empty beautiful subsets of the array nums.

// Input: nums = [2,4,6], k = 2
// Output: 4
// [2, 4, 6] -> [2], [4], [6], [2, 4], [4, 6], [2, 6], [2, 4, 6]
// output 4 as [2], [4], [6], [2, 6]

// Constraints:
// 1 <= nums.length <= 20
// 1 <= nums[i], k <= 1000

// this is approach of amking all the subsets and then checking if it is good or not
class Solution {
public:
    bool checkIsNice(vector<int> subset, int k){
        for(int i=0; i<subset.size(); i++){
            for(int j=i; j<subset.size(); j++){
                if(abs(subset[j] - subset[i]) == k) return false;
            }
        }
        return true;
    }

    void helper(vector<int>& nums, int k, vector<int> subset, int &ans, int i){
        if(i == nums.size()){
            if(checkIsNice(subset, k) == true) ans++;
            return;
        }

        // selecing
        subset.push_back(nums[i]);
        helper(nums, k, subset, ans, i+1);
        subset.pop_back();

        // not selecting
        helper(nums, k, subset, ans, i+1);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> subset;
        int ans = 0;
        helper(nums, k, subset, ans, 0);
        // we also have to remove the non empty subset
        return ans - 1;
    }
};


// instead of the unordered_map we can use vector also
class Solution {
public:
    void helper(vector<int>& nums, int k, vector<int> &subset, int &ans, int i){
        if(i == nums.size()){
            ans++;
            return;
        }

        // abs(x - nums[i]) = k;
        // x - nums[i] == k
        // nums[i] - x == k
        if(count(subset.begin(), subset.end(), nums[i] - k) > 0 || count(subset.begin(), subset.end(), nums[i] + k) > 0){
            cout<<nums[i]<<endl;
            return helper(nums, k, subset, ans, i+1);
        }

        // selecing
        subset.push_back(nums[i]);
        helper(nums, k, subset, ans, i+1);
        subset.pop_back();

        // not selecting
        helper(nums, k, subset, ans, i+1);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> subset;
        int ans = 0;
        helper(nums, k, subset, ans, 0);
        // we also have to remove the non empty subset
        return ans - 1;
    }
};


// approach of making all the good subsets
// recurssion 
class Solution {
public:
    void helper(vector<int>& nums, int k, unordered_map<int, int> &m, int &ans, int i){
        if(i == nums.size()){
            ans++;
            return;
        }

        // not selecting
        helper(nums, k, m, ans, i+1);

        // abs(x - nums[i]) = k;
        // x - nums[i] == k
        // nums[i] - x == k
        if(m[nums[i] - k] == 0 && m[nums[i] + k] == 0){
            m[nums[i]]++;
            helper(nums, k, m, ans, i+1);
            m[nums[i]]--;
        }
    
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ans = 0;
        helper(nums, k, m, ans, 0);
        // we also have to remove the non empty subset
        return ans - 1;
    }
};
