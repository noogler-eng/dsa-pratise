// Merge K Sorted Arrays
// QUESTION - https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-k-sorted-arrays

#include<iostream>
#include<queue>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int K){
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            pq.push(arr[i][j]);
        }
    }

    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}