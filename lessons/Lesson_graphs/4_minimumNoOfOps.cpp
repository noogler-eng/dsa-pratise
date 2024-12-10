// minimum no of operations
// remember when we have to find the level, no of operations use pairs

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// time complexity o(N)
// space complexity o(N)
// this is not based on bfs, it is general approach
int find_minimum_no_of_operations(int start, int end, vector<int> arr, int n){
    vector<bool> isVis;
    isVis[start] = true;

    queue<pair<int, int>> p;
    p.push({start, 0});

    while(!p.empty()){
        int value = p.front().first;
        int level = p.front().second;
        p.pop();

        if(value == end) return level;
        for(int i=0; i<n; i++){
            int dest = value * arr[i];
            if(dest <= end && !isVis[dest]){
                isVis[dest] = true;
                p.push({dest, level+1});
            }
        }
    }
    return -1;
}