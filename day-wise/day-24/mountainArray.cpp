// QUESTION - https://leetcode.com/problems/valid-mountain-array/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // strictly increasing then striclty decresing
        if(arr.size() < 3) return false;
        bool isIncreasing = true;
        if(arr[0] > arr[1]) return false;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] > arr[i-1] && isIncreasing) continue;
            else if(arr[i] > arr[i-1] && isIncreasing == false) return false;

            if(arr[i] == arr[i-1]) return false;
            
            if(arr[i] < arr[i-1] && isIncreasing) isIncreasing = false;
            else if(arr[i] < arr[i-1] && isIncreasing == false) continue;
            else if(arr[i] > arr[i-1] && isIncreasing == false) return false;
        }
        if(isIncreasing != false) return false;
        return true;
    }
};