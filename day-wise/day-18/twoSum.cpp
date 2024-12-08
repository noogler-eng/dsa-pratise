// QUESTION - https://leetcode.com/problems/two-sum/description/

#include<iostream>
#include<vector>
using namespace std;

vector<int> two_sum(vector<int> nums, int target){
    vector<pair<int, int>> new_nums(nums.size());
    for(int i=0; i<nums.size(); i++) new_nums[i] = {nums[i], i};
    
    sort(new_nums.begin(), new_nums.end(), [](pair<int, int> &x, pair<int, int> &y){
        return x.first < y.first;
    });

    int low = 0;
    int high = new_nums.size()-1;

    vector<int> ans;

    // not use = as there must be no arr[low] == arr[high] && low != high
    // we have to push the index so be carefull
    while(low < high){
        if(new_nums[low].first+new_nums[high].first == target) {
            ans.push_back(new_nums[low].second);
            ans.push_back(new_nums[high].second);
            break;
        }else if(new_nums[low].first+new_nums[high].first < target){
            low++;
        }else{
            high--;
        }
    }

    return ans;
} 

int main(){
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans = two_sum(nums, 9);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}