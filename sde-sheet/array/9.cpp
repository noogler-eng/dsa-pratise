// QUESTION - https://leetcode.com/problems/merge-sorted-array/

#include<iostream>
#include<vector>
using namespace std;
// time complexity o(N) + NLogN
// space complexity o(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() == 0) return;

        int i=m-1, j=0;
        while(i >= 0 && j < nums2.size()){
            if(nums1[i] > nums2[j]){
                swap(nums1[i], nums2[j]);
                i--;
                j++;
            }else{
                break;
            }
        }

        i = m;
        j = 0;
        while(i < nums1.size() && j < nums2.size()){
            nums1[i] = nums2[j];
            i++;
            j++;
        }

        sort(nums1.begin(), nums1.end());
    }
};