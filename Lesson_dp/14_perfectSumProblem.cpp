// QUESTION - https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space complexity o(2N)
int no_of_subsets(vector<int> nums, int target){
    vector<vector<int>> table(nums.size()+1, vector<int>(target+1, 0));
    table[0][0] = 1;

    for(int i=1; i<nums.size()+1; i++){
        for(int j=0; j<target+1; j++){
            if(nums[i-1] <= j){
                table[i][j] = table[i-1][j-nums[i-1]] + table[i-1][j];
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }
    
    return table[nums.size()][target];
}

int main(){
    cout<<no_of_subsets({28, 4, 3, 27, 0, 24, 26}, 24)<<endl;
    return 0;
}