// QUESTION LINK: https://leetcode.com/problems/number-of-1-bits/

#include<iostream>
using namespace std;

// time complexity o(N)
// space complexity o(1)
int no_of_set_bits(int n){
    int count = 0;
    while(n != 0){
        if(n & 1 == 1) count++;
        n = n >> 1;
    }
    return count;
}

int main(){
    cout<<no_of_set_bits(5)<<endl;
    return 0;
}