// QUESTION - https://leetcode.com/problems/maximum-subarray/description/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N)
// space complexity O(1)
int maxSubArray(vector<int> arr){
    int maxSum = INT_MIN, sum;
    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];
        maxSum = max(sum, maxSum);
        if(sum < 0) sum = 0;
    }
    return maxSum;
}