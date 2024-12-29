// Make an Array Strictky Increasing
// QUESTION - https://leetcode.com/problems/make-array-strictly-increasing/
// this is combination of greedy + dp

#include<iostream>
#include<vector>
using namespace std;

// Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
// Output: 1
// Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].

// Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
// Output: 2
// Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

// Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
// Output: -1
// Explanation: You can't make arr1 strictly increasing.
class Solution {
public:
    // we have to minimize the no of operations
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        vector<int> table(arr1.size() + 1);
        table[0] = 0;

        for(int i=1; i<arr1.size()+1; i++){
            int replacing = INT_MAX;
            // here when the number is making some error 
            // two conditions we have 
            // either replace
            // either leave
            if(arr1[i] <= arr1[i-1]){
                if()
                // replacing
                for(int j=0; j<arr2.size(); j++){
                    if(arr2[j] > arr1[i-1] && arr2[j] < arr1[i]){
                        int replacing = 1 + table[i-1];
                    }
                }
                table[i] = min(replacing, notReplacing);
            }else{
                continue;
            }
        }
    }
};