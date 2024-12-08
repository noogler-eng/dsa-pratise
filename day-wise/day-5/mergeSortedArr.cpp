// https://leetcode.com/problems/merge-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

// nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// time complexity o(NlogN)
// space complexity o(1)
void merge_sorted_arr(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int i = m, j = 0;
    while(i < nums1.size() && j < n){
        nums1[i] = nums2[j];
        i++;
        j++;
    }

    sort(nums1.begin(), nums1.end());
}

void print(vector<int> nums){
    for(auto i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge_sorted_arr(nums1, 3, nums2, 3);
    print(nums1);
    return 0;
}