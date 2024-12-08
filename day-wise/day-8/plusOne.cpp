// https://leetcode.com/problems/plus-one/

#include<iostream>
#include<vector>
using namespace std;

// increase the number by 1
// there is carray and sum concept
// time complexity o(N)
// space complexity o(1)
void plus_one(vector<int> &digits){
    int carry = 1;
    for(int i=digits.size()-1; i>=0; i--){
        int sum = 0;
        if(carry != 0){
            sum = digits[i] + carry;
            carry = sum / 10;
            int rem = sum % 10;
            digits[i] = rem;
        }else break;
    }
    if(carry!=0) digits.insert(digits.begin() + 0, carry);
}

int main(){
    vector<int> digits = {1, 2, 3};
    plus_one(digits);
    return 0; 
}