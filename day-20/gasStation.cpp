// QUESTION - https://leetcode.com/problems/gas-station/description/

#include<iostream>
#include<vector>
using namespace std;


// car with an unlimited gas tank
// it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station
// time complexity o(N)
bool is_traverse_back_possible(vector<int> gas, vector<int> costs){
    int n = gas.size();
    
    int total_gas = 0;
    int total_spent = 0;
    for(int i=0; i<gas.size(); i++){
        total_gas += gas[i];
        total_spent += costs[i];
    }

    // on a round if my spent is greater then never i will ride full
    if(total_gas - total_spent < 0) return false;

    int gasTank = 0;
    int start = 0;
    for(int i=0; i<gas.size(); i++){
        gasTank+=gas[i]-costs[i];
        if(gasTank < 0){
            start = i+1;
            gasTank = 0;
        }
    }

    return start;
}

int main(){
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> costs = {3, 4, 5, 1, 2};

}