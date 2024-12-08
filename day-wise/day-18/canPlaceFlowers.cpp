// QUESTION - https://leetcode.com/problems/can-place-flowers/

#include<iostream>
#include<vector>
using namespace std;

// n means we have to plant n flowers in flowerBed
// 1 means planted, 0 means non planted
// time complexity o(N)
// space complexity o(1)
bool can_place_flower(vector<int> flowerBed, int n){
    if(n == 0) return true;
    if(flowerBed.size() == 1){
        if(flowerBed[0] == 1) return false;
        else return true;
    } 
    
    for (int i = 0; i < flowerBed.size(); i++) {
        if (flowerBed[i] == 1)
            continue;
        else {
            if (i == 0 && flowerBed[i + 1] == 0) {
                n--;
                flowerBed[i] = 1;
            } else if (i == flowerBed.size() - 1 && flowerBed[i - 1] == 0) {
                n--;
                flowerBed[i] = 1;
            } else if (i!=0 && i!=flowerBed.size()-1 && flowerBed[i - 1] == 0 && flowerBed[i + 1] == 0) {
                n--;
                flowerBed[i] = 1;
            } else {}
        }
        if(n == 0) return true;
    }
    
    return false;
}

int main(){
    vector<int> flowerBed = {1, 0, 0, 0, 1};
    cout<<can_place_flower(flowerBed, 2)<<endl;
    return 0;
}