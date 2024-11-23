// QUESTION LINK:  https://leetcode.com/problems/jump-game-iv/

#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

// 100, -23, -23, 404, 100, 23, 23, 23, 3, 404
// arr[i] == arr[j] where i!=j
// we can move (i-1), (i+1), move where (arr[i] == arr[j] && i!=j)
int minimum_no_steps(vector<int> arr){
    if(arr.size() == 1) return 0;

    int score = arr[0];
    unordered_map<int, vector<int>> m;
    int max_score_now = arr[0], i=1;

    for(int i=0; i<arr.size(); i++) m[arr[i]].push_back(i);
    queue<pair<int, int>> q;
    // index, steps
    q.push({0, 0});
    unordered_set<int> visited;
    visited.insert(0);

    while(!q.empty()){
        int index = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(index == arr.size()-1) return steps;
        vector<int> neighbors;
        if (index + 1 < arr.size()) neighbors.push_back(index + 1);
        if (index - 1 >= 0) neighbors.push_back(index - 1);

        if(m.count(arr[index])) {
            neighbors.insert(neighbors.end(), m[arr[index]].begin(), m[arr[index]].end());
            m.erase(arr[index]); // Avoid redundant processing
        }

        for (int neighbor : neighbors) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, steps + 1});
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    cout<<minimum_no_steps(arr)<<endl;
    return 0;
}