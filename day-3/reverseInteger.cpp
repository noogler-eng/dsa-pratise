//QUESTION LINK:  https://leetcode.com/problems/reverse-integer/

#include<iostream>
using namespace std;

// time complexity o(N)
// space compelxity o(1)
int reverseInteger(int x_num){
    long long int reverseNumber = 0;
    int sign = x_num > 0 ? 1: -1;
    int num = abs(x_num);
    
    while(num != 0){
        int r = num % 10;
        if(reverseNumber > INT_MAX / 10) return 0;
        reverseNumber = (reverseNumber * 10) + r;
        num = num / 10;
    }

    reverseNumber = sign*reverseNumber;
    return reverseNumber;
}


int main(){
    int num = 123;
    cout<<reverseInteger(num)<<endl;
    return 0;
}