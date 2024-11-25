// QUESTION - https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum._842494?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION
// here the numbers of array are non-negative

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space compelxity o(2N)
bool can_partition(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
        
    int total_sum = 0;        
    for(int i=0; i<nums.size(); i++) total_sum+=nums[i];
    
    int n = nums.size();
    vector<vector<bool>> table(n+1, vector<bool>(total_sum+1, false));
    for(int i=0; i<n+1; i++) table[i][0] = true; 
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<total_sum+1; j++){
            if(nums[i-1] <= j){
                table[i][j] = table[i-1][j-nums[i-1]] || table[i-1][j];
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }

    int to_find = total_sum / 2;
    int ans = INT_MAX;
    for(int i=0; i<=to_find; i++) {
        if(table[n][i] == true) {
            ans = min(ans, total_sum - (2 * i));
        }
    }

    return ans;
}

int main(){
    vector<int> ele = {1, 5, 11, 5};
    cout<<can_partition(ele)<<endl;
    return 0;
}