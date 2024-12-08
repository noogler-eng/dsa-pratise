// QUESTION LINK: https://leetcode.com/problems/a-number-after-a-double-reversal/

#include<iostream>
using namespace std;

// 526
// 1800
// we have to return is original number is same or not
// time complexity o(N)
// space complexity o(1)
int after_double_reversal(int num){
    int originalNum = num;
    while(num != 0){
        int r = num % 10;
        if(r != 0) break;
        num = num / 10;
    }

    if(originalNum == num) return true;
    return false;
}

int main(){
    int num = 1800;
    cout<<after_double_reversal(num)<<endl;
}