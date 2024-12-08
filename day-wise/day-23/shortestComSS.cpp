// QUESTION - https://leetcode.com/problems/shortest-common-supersequence/submissions/1470077774/
// hard question

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// time complexity o(N*N)
// space complexity o(N*N)
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();

        vector<vector<int>> table(n1+1, vector<int>(n2+1, 0));
        for(int i=1; i < n1+1; i++){
            for(int j=1; j < n2+1; j++){
                if(str1[i-1] == str2[j-1]){
                    table[i][j] = table[i-1][j-1] +  1;
                }else{
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }

        // now we are making the string
        // if eqal then add directly, othrwise take that one which have larges commn subseq
        int i = n1, j = n2;
        string result = "";
        while(i > 0 && j > 0){
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];  
                i--; 
                j--;
            } else {
                if (table[i - 1][j] > table[i][j - 1]) {
                    result += str1[i - 1];  
                    i--;
                } else {
                    result += str2[j - 1]; 
                    j--;
                }
            }
        }

        while (i > 0) {
            result += str1[i - 1];
            i--;
        }

        while (j > 0) {
            result += str2[j - 1];
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};