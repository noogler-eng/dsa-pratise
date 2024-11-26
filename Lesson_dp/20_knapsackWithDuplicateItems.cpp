// QUESTION - https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space complexity o(2N)
// we can take a same bag infine number of times
int max_profit_from_unbounded_knapsack(vector<int> wt, vector<int> val, int capacity){
    vector<vector<int>> table(wt.size()+1, vector<int>(capacity+1, 0));
    for(int i=1; i<wt.size()+1; i++){
        for(int j=1; j<capacity+1; j++){
            if(wt[i-1] <= j){
                table[i][j] = max((table[i][j-wt[i-1]] + val[i-1]), table[i-1][j]);
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }
    return table[wt.size()][capacity];
}

int main(){
    vector<int> wt = {1, 1};
    vector<int> val = {2, 1};
    int capacity = 3;
    cout<<max_profit_from_unbounded_knapsack(wt, val, capacity)<<endl;
    return 0;
}