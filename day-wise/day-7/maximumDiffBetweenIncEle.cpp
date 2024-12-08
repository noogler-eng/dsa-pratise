// QUESTION LINK: https://leetcode.com/problems/maximum-difference-between-increasing-elements/ 

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space compexlity o(1)
int max_difference(vector<int> nums){
    int max = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[j] - nums[i] > max){
                max = nums[j] - nums[i];
            }
        }
    }
    
    if(max <= 0) return -1;
    return max;
}

// time complexity o(N)
// space complexity o(1)
// simillar concept of buy and sell stack - 1 
int max_difference_o(vector<int> nums){
    int maxi = INT_MIN;
    int mini = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        maxi = max(nums[i] - mini, maxi);
        mini = min(nums[i], mini);
    }

    if(maxi <= 0) return -1;
    return maxi;
}

int main(){ 
    vector<int> nums = {7,1,5,4};
    cout<<max_difference(nums)<<endl;
    cout<<max_difference_o(nums)<<endl;
    return 0;
}