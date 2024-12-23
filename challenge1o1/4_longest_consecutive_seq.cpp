// QUESTION - https://leetcode.com/problems/longest-consecutive-sequence/
// Input: nums = [100,4,200,1,3,2]
// Output: 4

#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
using namespace std;

// extreme brute force is o(N*N)
// extreme space complexity o(1)

// alogithms that will work in NlogN
// space complexity o(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 1;
        int maxCount = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]+1){
                count++;
            }else if(nums[i] == nums[i-1]){
                continue;
            }else{
                count = 1;
            }
            maxCount = max(maxCount, count);
        }

        return n > 0 ? maxCount: 0;
    }
};

// input: nums = [102,4,100,1,101,3,2,1,1]
// approach: o(N)
// 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        // unordered_set, not in ascending order or sorted
        unordered_set<int> s;
        // it only stores unique elements
        for(auto i: nums) s.insert(i);

        // we will only that number which dont have its backward number having only forward number like 100 and 1
        // so overall it makes the time complexity o(2N) -> o(N)
        int count = 1;
        int maxCount = 0;
        for(auto i: s){
            if(s.find(i-1) == s.end()){
                int cnt = 1;
                int x = i;
                while(s.find(x+1) != s.end()){
                    cnt++;
                    x++;
                }
                maxCount = max(maxCount, count);
            }
        } 
        return maxCount;
    }
};