// Task Scheduler
// QUESTION - https://leetcode.com/problems/task-scheduler/description/
// nice question

#include<iostream>
#include<vector>
using namespace std;

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

// steps 1. finding the frequcy of the maxium repeating char
// steps 2. we need to use the hashmap as we require the always maximum value at each steps
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> m;
        for(int i=0; i<tasks.size(); i++) m[tasks[i]]++;
        priority_queue<pair<int, int>> mq;
        for(auto i: m){
            mq.push({i.second, i.first});
        }

        int top_fre = mq.top().first-1;
        int no_of_slots = n * top_fre;
        mq.pop();
        while(!mq.empty()){
            no_of_slots = no_of_slots - min(mq.top().first, top_fre);
            mq.pop();
        }

        return tasks.size() + max(0, no_of_slots);
    }
};

// simillar but easy to understand 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(auto ch:tasks) freq[ch-'A']++;
        sort(freq.begin(), freq.end(),greater<int>());

        int ideal=(freq[0]-1)*n;
        for(int i=1;i<freq.size();i++){
            ideal= ideal- min(freq[0]-1, freq[i]);
        }
        return tasks.size() + max(0, ideal);
    }
};