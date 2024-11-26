// QUESTION - https://leetcode.com/problems/target-sum/

#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> table){
    for(auto i: table){
        for(auto j: i) cout<<j<<" ";
        cout<<endl;
    }
}

// time complexity o(N*N)
// space complexity o(2N)
int no_of_ways_to_reach_target_sum(vector<int> nums, int target){
    int total_sum = 0;
    for(int i=0; i<nums.size(); i++) total_sum += nums[i];
    
    // simillar concept only diff of way of seeing the question
    // half is positive and haslf is negative
    // s1 - s2 = target
    // s1 + s2 = total_sum
    // 2 * s1 = ts + target
    // means ts + target must be even
    if(((total_sum + target) % 2 != 0) || total_sum < target || (total_sum + target) < 0) return 0;    
    int to_find_no_of_subsets = ( total_sum + target ) / 2;
    vector<vector<int>> table(nums.size()+1, vector<int>(to_find_no_of_subsets+1, 0));
    table[0][0] = 1;

    for(int i=1; i<nums.size()+1; i++){
        for(int j=0; j<to_find_no_of_subsets+1; j++){
            if(nums[i-1] <= j){
                table[i][j] = table[i-1][j-nums[i-1]] + table[i-1][j];
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }
    
    print(table);

    return table[nums.size()][to_find_no_of_subsets];
}

int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    cout<<no_of_ways_to_reach_target_sum(nums, 3)<<endl;
    return 0;
}