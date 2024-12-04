#include<iostream>
#include<vector>
#include<string>
using namespace std;

// time complexity o(N*N)
// space complexity o(N*N)
// no of steps = no of unwanted characters
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        vector<vector<int>> table(n1+1, vector<int>(n2+1, 0));
        for(int i=1; i<n1+1; i++){
            for(int j=1; j<n2+1; j++){
                if(word1[i-1] == word2[j-1]){
                    table[i][j] = table[i-1][j-1] + 1;
                }else{
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }

        return n1 + n2 - (2 * table[n1][n2]);
    }
};