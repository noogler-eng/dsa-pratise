// https://leetcode.com/problems/complement-of-base-10-integer/

#include<iostream>
using namespace std;

// 5 -> 101 ^ 1
// ->   010 ----- 
// time complexity o(N)
// space complexity o(1)
int binary_complement_of_number(int num){
    int o_num = num;
    int x = 0;
    
    if(num == 0) return 1;
    while(num != 0){
        x = (x << 1) + 1;
        num = num >> 1;
    }

    return o_num ^ x;
}


int main(){
    int num = 5;
    cout<<binary_complement_of_number(num)<<endl;
    return 0;
}