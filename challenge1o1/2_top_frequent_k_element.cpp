// QUESTION - https://leetcode.com/problems/top-k-frequent-elements/description/
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

#include<iostream>
#include<vector>
using namespace std;

// there is concept of the min heap to get the top k frequent elqment
// time complexity o(N)
// space complexity o(N+K);
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }

        for(auto i: m){
            pq.push({i.second, i.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};