// Replace Element By The Rank
// QUESTION - https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-elements-by-its-rank-in-the-array

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<arr.size(); i++){
            pq.push({arr[i], i});
        }

        int i=0;
        while(!pq.empty()){
            int index = pq.top().second;
            int ele = pq.top().first;
            pq.pop();
            while(!pq.empty() && pq.top().first == ele){
                int index = pq.top().second;
                arr[index] = i+1;
                pq.pop();
            }
            arr[index] = i+1;
            i++;
        }

        return arr;
    }
};
