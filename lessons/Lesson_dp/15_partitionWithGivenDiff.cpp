// QUESTION - https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space complexity o(2N)
int count_partitions(vector<int> arr, int d) {
    int total_sum = 0;
    for(int i=0; i<arr.size(); i++) total_sum+=arr[i];
    
    // x + y = ts
    // x - y = d
    // 2x = ts + d
    // means d will always be even, if it is odd then return 0
    if ((total_sum + d) % 2 != 0 || total_sum + d < 0) return 0;
    
    int to_subset_sum = ((total_sum + d) / 2);
    vector<vector<int>> table(arr.size()+1, vector<int>(to_subset_sum+1, 0));
    table[0][0] = 1;
    
    for(int i=1; i<arr.size()+1; i++){
        for(int j=0; j<to_subset_sum+1; j++){
            if(arr[i-1] <= j){
                table[i][j] = table[i-1][j-arr[i-1]] + table[i-1][j];
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }
    
    return table[arr.size()][to_subset_sum];
}

int main(){
    cout<<count_partitions({5, 2, 6, 4}, 3)<<endl;
    return 0;
}