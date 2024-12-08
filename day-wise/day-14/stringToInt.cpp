#include<iostream>
using namespace std;

// time complexity o(N)
// space complexity o(1)
int stringToInt(string s){
    int i = 0;
    int isNumber = false;
    int sign = 1;
    long long int number = 0;
    while (i < s.length()) {
        if (s[i] == ' ' && isNumber == false) {
            i++;
            continue;
        }
        if (s[i] == '-' && isNumber == false) {
            sign = -1;
            isNumber = true;
            i++;
            continue;
        }
        if (s[i] == '+' && isNumber == false) {
            sign = 1;
            isNumber = true;
            i++;
            continue;
        }

        if (s[i] < '0' || s[i] > '9') return number * sign;
        number = number * 10 + (s[i] - '0');
        if(number > INT_MAX && sign == 1) return INT_MAX;
        if(number > INT_MAX && sign == -1) return INT_MIN;
        isNumber = true;
        i++;
    }
    return number / sign;
}

int main(){
    cout<<stringToInt("____-042")<<endl;
    cout<<stringToInt("1337c0d3")<<endl; 
    cout<<stringToInt("0-1")<<endl;
    cout<<stringToInt("words and 987")<<endl;
    return 0;
}