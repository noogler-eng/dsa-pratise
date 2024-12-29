// Number Of Ways To Reorder Array To Get Same BST
// QUESTION - https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/

// Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.
// For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
// Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.
// Since the answer may be very large, return it modulo 109 + 7.

// Input: nums = [2,1,3]
// Output: 1
// [2, 1, 3] - R, L, Right
// [2, 3, 1] - R, Right, L

// Input: nums = [3,4,5,1,2]
// Output: 5
// [3,4,5,1,2] - R, RL, L, RR, Right
// [3,1,2,4,5]
// [3,1,4,2,5]
// [3,1,4,5,2]
// [3,4,1,2,5]
// [3,4,1,5,2]

// this is binary search tree means mini comes left and maxi comes right
// always the root comes first
// fure sure 3 comes at first
// 5 will come after the 4
// 2 will come after the 1
// 1 and 4 comes after 3
// means we can arrange elemtns anywhere after its root

// _ _ _ _ _
// 3 _ _ _ _
//   2!
//     2!
// 2! * 2! + 1 = 5  
// return total_positions - 1 (c) total_roorts_left - 1 
// ncr means selecting the r from the any n

#include<iostream>
using namespace std;

// time complexity o(N*N)
// space complexity o(N*N)
class Solution {
public:
    vector<vector<long long>> table;
    int numOfWays(vector<int>& nums) {
        // no_of_ways = no_of_ways_to_left * order_left * order_right
        // no_of_left = ??
        long long mod = 1e9+7;
        int n = nums.size();

        table.resize(n+1);

        // time complexity o(N*N)
        for(int i=0; i<n+1; i++){
            table[i] = vector<long long> (i+1, 1);
            for(int j=1; j<i; j++){
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }
        
        long long ans = dfs(nums, mod);
        return ((ans % mod) - 1) % mod;
    }

    long long dfs(vector<int> &nums, long long mod){
        int n = nums.size();
        // No ordering is possible in the 2
        if(n <= 2) return 1;
        vector<int> left, right;
        for(int i=1; i<n; i++){
            // main root
            if(nums[i] < nums[0]){
                left.push_back(nums[i]);
            }else {
                right.push_back(nums[i]);
            }
        }

        long long left_res = dfs(left, mod) % mod;
        long long right_res = dfs(right, mod) % mod;
        int left_len = left.size();
        return (((table[n-1][left_len] * left_res) % mod) * right_res) % mod;
    }
};