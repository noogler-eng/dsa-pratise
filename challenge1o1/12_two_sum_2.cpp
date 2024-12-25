// QUESTION - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include<iostream>
#include<vector>
using namespace std;

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    // the array is already sorted
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ind(2, 0);
        int start = 0;
        int end = numbers.size()-1;
        while(start < end){
            if(numbers[start] + numbers[end] == target){
                ind[0] = start + 1;
                ind[1] = end + 1;
                break;
            }else if(numbers[start] + numbers[end] < target){
                start++;
            }else {
                end--;
            }
        }
        return ind;
    }
};