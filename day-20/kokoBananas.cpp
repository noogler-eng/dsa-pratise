// QUESTION LINK: https://leetcode.com/problems/koko-eating-bananas/

#include<iostream>
using namespace std;

// piles = {3, 6, 7, 11}
// h = 8
// Return the minimum integer k such that she can eat all the bananas within h hours.
// time complexity o(NlogN)
// space complexity o(1)
int min_k_value_of_koko_bananas(vector<int> piles, int h){
    int maxi = INT_MIN;
    for(int i=0; i<piles.size(); i++) maxi = max(maxi, piles[i]);
    
    long long int low = 1, high = maxi;
    while(low <= high){
        int mid = (low + high) / 2;
        long long hoursRequired = helper(piles, mid);
        if(hoursRequired <= h){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

long long helper(vector<int>& piles, int k){
    long long h = 0;
    for(int i=0; i<piles.size(); i++){
        h += ceil((double)piles[i] / (double)k);  
    }
    return h;
}

int main(){
    vector<int> arr = {30,11,23,4,20};
    int h = 6;
    cout<<min_k_value_of_koko_bananas(arr, h)<<endl;
    return 0;
}