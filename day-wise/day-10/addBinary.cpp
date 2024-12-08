// QUESTION LINK: https://leetcode.com/problems/add-binary/

#include<iostream>
using namespace std;

string reverse(string a){
    int start = 0;
    int end = a.size()-1;
    while(start <= end){
        swap(a[start], a[end]);
        start++;
        end--;
    }
    return a;
}

// add two binary numbers
string add_binary(string a, string b){
    string new_a = reverse(a);
    string new_b = reverse(b);
    int mini = min(new_a.length(), new_b.length());
    string ans = "";

    int i = 0, carry = 0;
    while(i < mini){    
        int digit_1 = new_a[i] - '0';
        int digit_2 = new_b[i] - '0';
        int sum = digit_1 + digit_2 + carry;
        int value = sum % 2;
        carry = sum / 2;
        ans+=value + '0';
        i++;
    }

    while(i < a.length()){
        int digit_1 = new_a[i] - '0';
        int sum = digit_1 + carry;
        int value = sum % 2;
        carry = sum / 2;
        ans+=value + '0';
        i++;
    }

    while(i < b.length()){
        int digit_1 = new_b[i] - '0';
        int sum = digit_1 + carry;
        int value = sum % 2;
        carry = sum / 2;
        ans+=value + '0';
        i++;
    }

    if(carry != 0) ans+=carry + '0';
    string new_ans = reverse(ans);
    return new_ans;
}

int main(){
    string a = "1011";
    string b = "101";
    cout<<add_binary(a, b)<<endl;
    return 0;
}