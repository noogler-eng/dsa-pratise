// QUESTION - https://leetcode.com/problems/top-k-frequent-elements/

#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

// time compelxity o(N+N)
// space complexity o(N+K), only k can take at a time by min heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // taking an min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        for(auto i: m){
            pq.push({i.second, i.first});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};