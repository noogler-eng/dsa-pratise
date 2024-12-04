// QUESTION - https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/1470043166/

#include<iostream>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space complexity o(N*N)
class Solution {
public:
    string reverse(string s){
        int start = 0;
        int end = s.length()-1;
        while(start <= end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }


    int minInsertions(string s) {
        int n = s.size();
        string r = reverse(s);
        vector<vector<int>> table(n+1, vector<int>(n+1, 0));

        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(s[i-1] == r[j-1]){
                    table[i][j] = table[i-1][j-1] + 1;
                }else{
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }

        return n - table[n][n];
    }
};