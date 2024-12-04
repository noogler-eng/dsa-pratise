#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
    string reverse(string s){
        int start = 0;
        int end = s.length()-1;
        while(start<= end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }

    // here subsequence will be handled by the connected blocks
    // if character mathes see diagonal as consuming both
    // if not then taking max of both the sideways
    // time complexity o(N*N) + o(N)
    // space complexity o(N*N)
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string r = reverse(s);
        vector<vector<int>> table(n+1, vector<int> (n+1, 0));

        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(s[i-1] == r[j-1]){
                    table[i][j] = table[i-1][j-1] + 1;
                }else{
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }

        return table[n][n];
    }
};