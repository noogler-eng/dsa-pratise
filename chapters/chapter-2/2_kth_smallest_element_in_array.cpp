// Kth Smallest Element In Array
// QUESTION - https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=kth-smallest-element

#include<iostream>
#include<queue>
using namespace std;

// smallest means max heap
int kthSmallest(vector<int> &arr, int k) {
    priority_queue<int> pq;
    for(int i=0; i<arr.size(); i++){
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }

    return pq.top();
}