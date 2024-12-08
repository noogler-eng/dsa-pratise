// QUESTION - https://leetcode.com/problems/count-good-numbers/

#include<iostream>
using namespace std;

// time compllexity o(N)
// space complexity o(1)
class Solution {
public:
    const int modulo = 1000000007;
    long long power(long long value, long long p) {
        long long result = 1;
        value = value % modulo;
        while (p > 0) {
            if (p % 2 == 1) {
                result = (result * value) % modulo;
            }
            value = (value * value) % modulo;
            p /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenDigits = 5;
        long long oddDigits = 4;

        long long even = (n + 1) / 2;
        long long odd = n / 2;
        long long ans = power(5, even) * power(4, odd);
        return ans % modulo;
    }
};