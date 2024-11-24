// QUESTION - https://leetcode.com/problems/minimum-positive-sum-subarray/

#include<iostream>
#include<vector>
using namespace std;

// brute is optmial here
// time complexity o(N*N)
// space complxity o(1)
int minimum_sum_subarray(vector<int>& nums, int l, int r) {
    int sum = 0, mini = INT_MAX;
    for(int i=0; i<nums.size(); i++){
        sum = 0;
        for(int j=i; j<nums.size(); j++){
            sum+=nums[j];
            if(j-i+1 >= l && j-i+1 <= r && sum > 0) mini = min(sum, mini);
        }
    }
    return mini == INT_MAX ? -1 : mini;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    cout<<minimum_sum_subarray(nums, 1, 2)<<endl;
    return 0;
}