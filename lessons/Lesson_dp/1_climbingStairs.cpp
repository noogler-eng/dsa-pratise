// https://leetcode.com/problems/climbing-stairs/description/
// Climbing Stairs

#include<iostream>
#include<vector>
using namespace std;

int bottom_up_method(int n, vector<int> store){
    if(n == 1 || n == 2) return store[n];
    if(store[n] != -1) return store[n];
    return store[n] = bottom_up_method(n-1, store) + bottom_up_method(n-2, store);
}

int no_of_ways_to_climb_o(int n){
    vector<int> store(n+1, -1);
    store[1] = 1;
    store[2] = 2;
    return bottom_up_method(n, store);
}

// solved using tabulation method
int no_of_ways_to_climb_o_o(int n){
    vector<int> table(n+1);
    // nothing done then 1 step
    table[0] = 1;
    // going to 1 takes 1 step
    table[1] = 1;

    for(int i=2; i<n+1; i++) table[i] = table[i-1] + table[i-2];
    return table[n];
}

// solved using recurssion
// time complexity o(2^N)
int no_of_ways_to_climb(int n){
    if(n == 1 || n == 2) return n;
    return no_of_ways_to_climb(n-1) + no_of_ways_to_climb(n-2);
}

int main(){
    int n = 2;
    cout<<no_of_ways_to_climb(n)<<endl;
    cout<<no_of_ways_to_climb_o(n)<<endl;
    cout<<no_of_ways_to_climb_o_o(n)<<endl;
    return 0;
}